#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc,string argv[])
{
    if (argc !=2)
    {
        printf("command line argument error\n");
        return 1;
    }

    for ( int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("command line argument error\n");
            return 1;
        }
    }

    printf("plaintext:");
    string text = get_string();
    printf("ciphertext:");
    for (int a = 0, b = 0,n = strlen(text); a < n; a++)
    {
        char key = argv[1][(b) % strlen(argv[1])];
        if (isalpha(text[a]))
        {
            if (isupper(text[a]))
            {
                char letter = text[a] - 65;
                char cipher = (letter + (key-65)%26)+65;
                b++;
                printf("%c", cipher);
            }#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc,string argv[])
{
    if (argc !=2)
    {
        printf("command line argument error\n");
        return 1;
    }

    for ( int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("command line argument error\n");
            return 1;
        }
    }

    printf("plaintext:");
    string text = get_string();
    printf("ciphertext:");
    for (int a = 0, b = 0,n = strlen(text); a < n; a++)
    {
        char key = argv[1][(b) % strlen(argv[1])];
        if (isalpha(text[a]))
        {
            if (isupper(text[a]))
            {
                char letter = text[a] - 65;
                char cipher = (((letter + key)-65)%26)+65;
                b++;
                printf("%c", cipher);
            }

        }

    }

}

        }

    }

}