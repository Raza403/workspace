#include <cs50.h>
#include <stdio.h>

void printname(string name);

 int main (void)
{

 printf ("your name : ");
 
 string s = GetString();
 
 printname (s);
 
}

void printname(string name)

 {
     printf ("hello, %s\n", name);
    
 }