#include <stdio.h>

#include <cs50.h>

int main (void)
{
    
    for (int i=65; i <65+26; i++)
    
    printf ("%c : %i\n", (char) i, i);
    
    for (int j=97; j<97+26; j++)
    
    printf("%c : %i\n", (char) j, j);
}