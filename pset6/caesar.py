import cs50
import sys
def main ():
    if len(sys.argv) != 2:
        print("Please enter one command line argument")
        exit(1)
    key = int(sys.argv[1])
    ptext = input("Please enter plain text:  ")
    ctext = []
    for i in range (len (ptext)):
        if ptext[i].isalpha():
            if ptext[i].islower():
                a = ((((ord(ptext[i])- 97) + key)%26) +97)
                ctext.append(chr(a))
            else:
                a = ((((ord(ptext[i])- 65) + key)%26) +65)
                ctext.append(chr(a))
        else:
            ctext.append(ptext[i])

    print ("{}".format(''.join(ctext)))
    
    
    
    
if __name__=="__main__":
    main()