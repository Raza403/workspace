#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    printf ("say something\n");
    char* t = GetString();
    printf("Say again\n");
    char* s = GetString();
    if (s != NULL && t != NULL )
    {
        if (strcmp(s , t)==0)
        {
            printf ("You enetred same");
        }
        else
        {
            printf ("You entered Different");
        }
    }
}