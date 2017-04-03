#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
int collatz( int n, int c);
int main (void)
{
4    printf("please enter a positive int\n");
    int n=GetInt();
    int count=0;
    collatz (n,count);
}
    int collatz (int n,int c)
{   
   
    if (n<1)
    {
        return 1;
    }
    else if (n>0)
    {   
        //base case is when n==1
        
        if (n==1)
        {
            c++;
            //print number of repition to make it 1
            printf("%i\n", c);
            return 0;
        }
        // if even
       else if ((n%2)==0)
        {
            return 1 + collatz(n/2,c++);
        }
        //if odd
        else if((n%2)==1)
        {
        return 1 + collatz(3*n+1,c++);
        }   
        
    }
    
}