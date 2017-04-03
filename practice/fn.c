#include <cs50.h>
#include <stdio.h>
int positiveint (void);
int main (void)

{
   int n = positiveint();
 printf ("thanks for the %i\n", n);   
}

int positiveint (void)

{
    int n;
    do
    
    {
        printf ("give me a positive int\n");
        
       n = GetInt();
        
    }
    
    while (n<1);
    
    return n;
}