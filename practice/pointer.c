#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    char* s = GetString();
    if (s == NULL)
    {
        return 1;
    }
    int i = 0;
    int n = strlen(s);
    for (i=0;i<n;i++)
    {
    printf ("%c\n", *(s+i));
    }
    
}