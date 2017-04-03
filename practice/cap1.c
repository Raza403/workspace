#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string s = GetString ();
    int n=strlen(s);
    for (int i=0;i<n;i++)
    {
        printf ("%c",toupper (s[i]));
    }
    
    printf ("\n");
    
}