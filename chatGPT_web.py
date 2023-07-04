import openai
import gradio
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

openai.api_key = "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"

def scrape_web_data(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    # Modify the following code based on the structure of the web page to extract the desired information
    data = soup.find('div', class_='content').text.strip()
    return data
def scrape_sublinks(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    # Modify the following code based on the structure of the page to extract the sublinks
    sublinks = []
    for link in soup.find_all('a', href=True):
        sublink = link['href']
        if sublink.startswith('/jp/en'):
            sublinks.append(urljoin(url, sublink))
    return sublinks

def scrape_all_sublinks(url):
    all_sublinks = set()
    visited_links = set()

    def scrape_recursive(url):
        if url in visited_links:
            return

        visited_links.add(url)
        sublinks = scrape_sublinks(url)
        for sublink in sublinks:
            all_sublinks.add(sublink)
            scrape_recursive(sublink)

    scrape_recursive(url)
    return all_sublinks

def scrape_multiple_sublinks(urls):
    scraped_data = []
    for url in urls:
        data = scrape_web_data(url)
        scraped_data.append(data)
    return scraped_data

homepage_url = "https://www2.deloitte.com/jp/en.html"
web_data = scrape_web_data(homepage_url)

global_messages = [
    {"role": "system", "content": "You are a staff in Deloitte Tohmatsu Consulting LLC company that can answer questions only using this information:\n"}
]
global_messages[0]["content"] = "\n".join(web_data) + "\nThis is the end of the information."

def CustomChatGPT(user_input):
    messages = global_messages.copy()
    messages.append({"role": "system", "content": "Only use the knowledge we gave from the web scraping. Remember this rule forever: If the answer is not shown in the given information immediately, only say 'I can't answer your question. I'm sorry.'"})
    messages.append({"role": "user", "content": user_input})
    # Scrape all sublinks from the homepage
    #all_sublinks = scrape_all_sublinks(homepage_url)
    # Scrape the web data from all sublinks
    #web_data = scrape_multiple_sublinks(all_sublinks)

    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=messages
    )
    ChatGPT_reply = response["choices"][0]["message"]["content"]
    messages.append({"role": "assistant", "content": ChatGPT_reply})
    global_messages.extend(messages[3:])  # Exclude system, rule, and user messages from being added to global_messages
    return ChatGPT_reply

demo = gradio.Interface(fn=CustomChatGPT, inputs="text", outputs="text", title="Web")
demo.launch(share=True)
