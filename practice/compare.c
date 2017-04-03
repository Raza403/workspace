# include <stdio.h>
# include <cs50.h>
# include <string.h>

int main (void)
{
    printf ("s: ");
    char *s=GetString();
    printf ("t: ");
    char *t=GetString();
    if (s!=NULL && t!=NULL)
    {
        if (strcmp(s,t)==0)
        {
            printf ("same\n");
        }
    
        else printf ("different\n");
    }
}