#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)

{
    string name=GetString();//used to getname from user.
    
    int lenth=strlen(name); //variable lenth=lenth of name||number of chars in the name.
    
    printf ("%c",toupper (name[0]));//printing first char in uppercase.

    int i=0;
    
    for (i=0;i<lenth;i++)
    
    if isspace(name[i])//checking if space in the name.
    
    {
        printf ("%c",toupper (name[i+1]));//printing char after space in uppercase.
        
    }
    
    printf ("\n");// new line at the end.
    
    
 
}