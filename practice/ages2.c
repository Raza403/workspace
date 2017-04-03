#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n;
    do
    {
        printf ("Please enter Number of people in the room\n");
        
        n= GetInt();
    
    }
    
    while (n<1);
    
    int ages[n];
    
    for (int i=0;i<n;i++)
    {
        printf("Age of person no %i : \n", i+1);
        
        ages[i]=GetInt();
        
    }
    
    printf ("Time passes\n");
    
    for (int i=0;i<n;i++)
    
{
    printf ("Age of %i person is %i after 1 year\n", i+1, ages[i]+1);
}
    
}
