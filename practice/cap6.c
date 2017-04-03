#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string s = GetString ();
   string n= toupper(s);
    printf ("%s\n",n);
}
    