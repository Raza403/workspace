#include <stdio.h>
#include <cs50.h>

int main (int argc, string argv[])
{   
    printf ("how many segments");
    int n= GetInt();
    for (int i=0;i<n;i++)
    printf ("%i:::%i:::::%s\n",argc,i,argv[i]);
}