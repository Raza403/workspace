#include <stdio.h>
#include <cs50.h>
int main (void)
{
    printf (" Please enter the string\n");
    char* s = malloc (50 * sizeof(char));
    scanf ("%s",s);
//int n = strlen (s);
  //  for (int i=0;i<n;i++)
    {
    printf ("You entered %s\n", s);
        
    }
}