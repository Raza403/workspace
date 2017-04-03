#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)

{
    char* s = GetString();
    int n = strlen(s);
    printf ("%s\n", s);
    char* t = malloc (n+1 * sizeof (char));
    if (t==NULL)
    {
        free(s);
        return 1;
    }
    for (int i=0;i<=n;i++)
    {
        t[i]=s[i];
        t[0]=toupper(t[0]);
        
        printf ("%c", *(t+i));
        }
        printf ("\n");
}
    
