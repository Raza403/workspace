//This code encrypt plain text using vigenere cypher.
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (int argc,string argv[])
{
    if (argc != 2)//argc must be 2
    
    {
        printf ("please enter 2 command line arguments\n");
        return 1;//Exit.
    }
    else
    {
        for (int i=0,n = strlen (argv[1]);i<n;i++)//checking if isalpha
        if (!isalpha (argv[1][i]))
        {
            printf ("must be alpha\n");//If any char not alpha then exit.
            return 1;//Exit
        }
        
    }

        string p = GetString();//Prompting user for plain text.
        int plen=strlen (p);//lenth of plain text||number of chars in the plain text.
        int klen=strlen (argv[1]);//lenth of key
        char key[klen];// string used as for key
        char txt[plen];//for converting string p to char txt.
        int b=0;//Used to count and round loop the key.
        for(int j=0;j<klen;j++)
        {
            if (isupper (argv[1][j]))
            {
                key[j]=(argv[1][j])-'A';//converting uppercase key to index 0
            }
            else
            {
                key[j]=argv[1][j]-'a';//converting lower case key to index 0
            }
        }
        for (int t=0;t<plen;t++)
        {
            txt[t]=p[t];//converting string p to char string txt.
        }
    
        for (int k=0;k<plen;k++)
       { b=b%klen;
        if (isalpha(txt[k]))//if p[k] is alpha then execute this loop so that key used only for alpha
        {   
              if (isupper(txt[k]))
            {
                
                printf ("%c",(((txt[k]-'A')+(key[b]))%26)+'A');//0 idex txt[k] then add key and finally adding 65 for A
                b++;
            }
            else
            {
                
                printf ("%c",(((txt[k]-'a')+(key[b]))%26)+'a');// same for lower case
                b++;
            }
            
        }
        else
        {
            printf ("%c",txt[k]);//if not alpha then print as it is
        }}
        printf("\n");
    return 0;//exit.
}