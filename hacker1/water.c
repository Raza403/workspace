#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main (void)
{
    int mins, bottels;
    
   do
    {
    
    printf ("How many mins you take shower\n");
    
    mins=GetInt () ;
    }
    
    while(mins<=0);
    
    bottels=mins*12;
    
    printf ("%d\n", bottels);
    
}