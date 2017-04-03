// This code encripts plain text by using caesar cypher.
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main (int argc,string argv[])

{
    if (argc!=2)//if command line arguments are not equel to 2.
    {
       printf("please enter 2 command line arguments\n");//Mustr enter 2 command line arguments.
        return 1;// Exit.
    }
 
   
  int key= atoi (argv[1]);//changing char at argv[1] to int.
 
  string txt = GetString();//Getting plain text from user.
  
  int len=strlen(txt);//Number of chars in txt.
  
  for (int i=0;i<len;i++)
  
  {
     if (isalpha(txt[i]))//if alphabet.
      {
          if (isupper(txt[i]))//if is upper case
          {
              int alpha=((((txt[i]-65)+key)%26)+65);//first make it 0 index then add key, gain covert back
              printf ("%c", alpha);
          }
          else //lower case
          {
              int alpha=((((txt[i]-97)+key)%26)+97);//first make it 0 index then add key, gain covert back
              printf("%c", alpha);
          }
      
            
        }
      else // if not alpha
            {
                printf ("%c",txt[i]);//Print as it is.
            }
  }
    printf("\n");
    return 0;//Exit.
}