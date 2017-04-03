#include <stdio.h>
#include <cs50.h>
int sigma(int m);
int main (void)
{
    int n=0;
    int sum=0;
    do
    {
    printf("Please give a positive int\n");
    n = GetInt();
    }
    while (n<1);
    sum = sigma(n);
    printf("%i\n",sum);
}
int sigma (int m)
{
    if (m<=0)
    {
        return 0;
    }
    else
    {
        return m+sigma(m-1);
    }
}