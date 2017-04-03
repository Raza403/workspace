#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[])

{

    for (int i=1;i<argc;i++)
    {
    int n=strlen (argv[i]);
    
    for (int j=0;j<n;j++)
    
    printf ("%c\n", argv[i][j]);
    }
}