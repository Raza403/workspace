#include <stdio.h>
# include <cs50.h>
#include <string.h>
int main (void)
{
    char* s=GetString();
    int n=strlen(s);
    printf ("%i         %s\n",n, s);
    return 0;
}