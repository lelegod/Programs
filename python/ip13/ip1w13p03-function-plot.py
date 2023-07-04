# let function be "sin(x)"
# let minimum  be "-2*pi"
# let maximum  be "2*pi"
#
# let plot(points) be
#    let miny be the minimum of all the points
#    let maxy be the maximum of all the points
#    if miny >= maxy then let miny be miny - 1
#    let scale be 400 / (maxy - miny)
#    open a turtle window with size 500 x 500
#    lift the turtle pen up
#    let npoints be length of points
#    let xx range from 0 to npoints - 1
#        let y be points[xx]
#        send turle to (-200 + xx * 400 / npoints, -200 + (y - miny) * scale)
#        put the turle pen down
#    lift the turtle pen up
#    send turtle to (0, 0)
#
# repeat forever
#    print "1) change function:" and the current value of function
#    print "2) change minimum: " and the current value of minimum
#    print "3) change maximum: " and the current value of maximum
#    print "4) plot function"
#    print "5) clear"
#    print "6) exit"
#    print "choice: "
#    let choice be the user's input
#    if choice is "1"
#        print "new function: " and let function be the user's input
#        continue the loop
#    if choice is "2"
#        print "new minimum: " and let minimum be the user's input
#        continue the loop
#    if choice is "3"
#        print "new maximum: " and let maximum be the user's input
#        continue the loop
#    if choice is "4"
#        let mini be the result of evaluating minimum
#        let maxi be the result of evaluating maximum
#        let points be an empty list
#        let xx range from 0 to 400
#            let x be mini + (maxi - mini) * xx / 400
#            let y be the result of evaluating function
#            append y to the list points
#        call plot(points)
#        continue the loop
#    if choice is "5"
#        exit from the program
from math import*
from turtle import*

function = "sin(x)"
xmin = "-2*pi"
xmax = "2*pi"

def plot(points):
    x = xmin
    ymin = min(points)
    ymax = max(points)
    if ymin == ymax:
        ymin = ymin-1
    scale = 400/(ymax-ymin)
    setup(500,500)
    up()
    npoints = len(points)
    for xx in range(0,npoints-1):
        y = points[xx]
        goto(-200+xx*400/npoints,-200+(y-ymin)*scale)
        down()
    up()
    goto(0,0)

while True:
    print("1) change function:",function)
    print("2) change minimum:",xmin)
    print("3) change maximum:",xmax)
    print("4) plot function")
    print("5) exit")
    choice = input("choice: ")
    if choice == "1":
        function = input("new function: ")
        continue
    if choice == "2":
        xmin = input("new minimum: ")
        continue
    if choice == "3":
        xmax = input("new maximum: ")
        continue
    if choice == "4":
        mini = eval(xmin)
        maxi = eval(xmax)
        points = []
        for xx in range(0,400):
            x = mini+(maxi-mini)*xx/400
            y = eval(function)
            points.append(y)
        plot(points)
        continue
    if choice == "5":
        break
        
    
        

