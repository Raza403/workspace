#include <stdio.h>
#include <string.h>
# include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main (void)
{
    char* s=GetString();
    // First error here (invalid operands to binary expression ('void *' and 'unsigned long'))
    char* t = malloc((strlen(s)+1) * sizeof(char));
    if (t==NULL)
    {
        free (s);
        return 1;
    }
    for (int i=0, n=strlen(s);i<n;i++)
    {
        t[i]=s[i];
        
    }
    //Second error here(incompatible pointer to integer conversion assigning to 'char' from 'int (int)')
    t[0]= toupper(t[0]);
    printf("%s\n", s);
    printf("%s\nahmed",t);
    
    free(s);
    free(t);
}