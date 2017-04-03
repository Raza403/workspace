#include <stdio.h>
#include <cs50.h>

int main (void)// HAHAHA first complete program without error and desired output.
{
    int numbers [7];
    
    for (int i=0;i<6;i++)
    {
        printf ("Give me number: %i\n",(i+1) );
        
        numbers[i]=GetInt();
    }
    
    for (int j=0;j<6;j++)
    {
      printf ("The no %i is %i\n", j,numbers[j]);    
    }
}
