import cs50

while (True):
    print("please give positive input")
    dlr = cs50.get_float()
    if dlr > 0:
        break
cents = round (dlr*100)
counter = 0
while (cents >= 25):
    cents -= 25
    counter += 1
    
while (cents >= 10):
    cents -= 10
    counter += 1
   
while (cents >= 5):
    cents -= 5
    counter += 1
    
while (cents > 0):
    cents -= 1
    counter += 1    
   
print (counter)