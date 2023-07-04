# let getYesNo(prompt) be
#    repeat forever
#        print prompt + " (yes/no): "
#        let answer be user response converted to lower case
#        if "yes" start swith answer then return True
#        if "no" starts with answer then return False
#        print "I don't understand you; please type yes or no."
#
# repeat forever
#    print "Think of a number between 1 and 100."
#    print "I will try to guess it."
#    print "Each time I guess, tell me if I am HIGH, LOW, or CORRECT."
#    let lo be 1 and hi be 100 and count be 0
#    repeat forever
#        if hi < lo then inform the user that they are cheating then break out of the inner loop
#        let mi be (lo + hi) // 2
#        print "My guess is:" and mi
#        increment count by 1
#        print "Am I HIGH, LOW, or CORRECT: "
#        let answer be the user's input converted to lower case
#        if "high" starts with the answert then let hi be mi - 1
#        else if "low".starts with the answer then let lo be mi + 1
#        else if "correct" starts with the answer then
#            print "I got it in" and count and "attempts."
#            break out of the inner loop
#        else print "I did not understand you." and continue the inner loop
#    let again be getYesNo("Play again")
#    if again is false then break from the outer loop

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

while True:
    print("Think of a number between 1 and 100")
    print("I will try to guess it")
    print("Each time I guess, tell me if I am HIGH, LOW, or CORRECT")
    lo = 1
    hi = 100
    count = 0
    while True:
        if hi < lo:
            print("You are cheating!")
            break
        mi = (lo+hi)//2
        print("My guess:", mi)
        count = count + 1
        answer = input("Am I HIGH, LOW, or CORRECT: ")
        answer = answer.lower()
        if "high".startswith(answer):
            hi = mi - 1
        elif "low".startswith(answer):
            lo = mi + 1
        elif "correct".startswith(answer):
            print("I got it in in ",count,"attempts.")
            break
        else:
            count = count - 1
            print("I don't understand you")
    again = getYesNo("Play again")
    if again == False:
        print("Thanks for playing")
        break
    
