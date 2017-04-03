#include <stdio.h>
#include <cs50.h>
int coll (int a,int c);
int main (void)
{
    printf("Please enter the int\n");
    //Getting input from user
    int n = GetInt();
    //Used for counting no of iterations
    int count = 0;
    //Calling function
    int ans = coll (n, count);
    //Printing output of function
    printf ("%i\n", ans);
}

int coll (int a,int c)
{
    //if a is odd number
    if(a%2==1 && a!=1)
    {
        return coll ((3*a)+1, c+1);
    }
     //If a is even number
    else if(a%2==0 && a!=1)
    {
       return coll (a/2, c+1);
    }
    
    //Base case returns the value of c
    
    else
        return c;
}