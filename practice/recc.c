#include <stdio.h>
#include <cs50.h>
long fact (long a);
int main (void)
{
    printf ("Please enter int\n");
    long n = GetInt();
    long answer = fact (n);
    printf ("%li\n",answer);
}

long fact (long a)
{
    if (a==1)
    {
        return 1;
    }
    else
    {
        return a * fact(a-1);
    }
}