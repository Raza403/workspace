import cs50

while (True):
    print ("Please give height of the half Peramid from 1 to 23")
    height = cs50.get_int()
    if height > 0 and height <24:
        break
for i in range (height):
    for space in range (height-i-1):
        print(" ",end="")
    for symbol in range (i+2):
        print ("#", end="")
    print()