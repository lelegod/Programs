# let getYesNo(prompt) be
#    repeat forever
#        print prompt + " (yes/no): "
#        let answer be user response converted to lower case
#        if "yes" start swith answer then return True
#        if "no" starts with answer then return False
#        print "I don't understand you; please type yes or no."
#
# repeat forever
#    let number be a random number between 1 and 100 inclusive
#    let count be 0
#    print "I have thought of a number between 1 and 100."
#    print "Try to guess the number."
#    repeat forever
#        print "Your guess: "
#        let guess be the user's input converted to an integer
#        increase count by 1
#        if guess < number, print "Too low." and continue from the start of the inner loop
#        if guess > number, print "Too high." and continue from the start of the inner loop
#        print "You guessed the number in " then count then " attempts."
#        break from the inner loop
#    let again be getYesNo("Play again")
#    if again is false then break from outer loop

import random

def getYesNo(prompt):
    while True:
        answer = input(prompt + " (yes/no): ")
        answer = answer.lower()
        if "yes".startswith(answer):
            return True
        if "no".startswith(answer):
            return False
        print("I don't understand you; please type YES or NO.")
        
def check(x):
    try:
        result = int(x)
    except:
        result = None
    if result == None:
        print("Only integers")
        return None 
    if result > 100 or result < 1:
        print("Only number between 1 to 100")
        return None
    return result

playing = True

while playing == True:
    print("I have thought of a number between 1 and 100")
    print("Try to guess the number")
    count = 0
    number = random.randint(1,100)
    incorrect = True
    while incorrect == True:
        guess = check(input("Your guess: "))
        if guess == None:
            continue
        count = count + 1
        if guess < number:
            print("too low")
        if guess > number:
            print("too high")
        if guess == number:
            print("correct")
            print("You guessed the number in ",count, " attempts")
            incorrect = False
    again = getYesNo("Play again")
    if again == False:
        print("Thanks for playing")
        break
    
