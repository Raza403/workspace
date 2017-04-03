# include <stdio.h>
# include <cs50.h>
# include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (void)
{
    printf ("s: ");
    char *s=GetString();
    printf ("Origional text: %s\n", s);
    int n=strlen(s);
    char *t=malloc (n)+1;
    if (t==NULL)
    {
        return 1;
    }
    else 
    {
        for (int i=0;i<=n;i++)
        {
            t[i]=s[i];
            
           t[0]= toupper (t[0]);
         
         printf ("%c",*(t+i));
        }
       printf("\n");
    }
}