#include <stdio.h>
#include <cs50.h>
#include <string>

int main (void)

{   
    
    string s=GetString();
    int n=strlen(s);
    
    for (int i=0;i<n;i++)
    
    
    printf ("is %c", s[i]);
}