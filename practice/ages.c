#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)

{
    int n=0, age[n==0];
    do
    
    {
        printf("How many people in the room?\n");
        
        n=GetInt();
    }
    
    while (n<1);
    

    
    for (int i=0;i<n;i++)
    
    {
        
        printf ("Enter the age of %i person\n", i+1);
        
        age[i]=GetInt();
        //new
    }
    
    for (int i=0;i<n;i++)
    
    printf("age of %i person is %i\n", i+1, age[i]);
    
}