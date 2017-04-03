#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    string p=GetString();
    string k=GetString();
    int i;
    int n=strlen(p);
    int nk=strlen(k);
    
    for (i=0;i<n;i++)
    {
        if (isalpha(p[i]))
        {
            for (int j=0;j<nk;j++)
            {
                
            
                int final= ((p[i]-'a')+(k[i%nk]-'a'));
                printf ("%c",final+'a');
            }
        }
    }
}