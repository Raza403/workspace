#include <stdio.h>
#include <cs50.h>
int sumrec(int a);
int main (void)
{
    printf (" Enter the int\n");
    int n = GetInt();
    if (n==0)
    {
        printf ("0\n");
        return 0;
    }
    int ans = sumrec(n);
    printf ("%i\n", ans);
}

int sumrec(int a)
{
    if (a == 1)
    {
        return 1;
    }
    else 
    {
        return a+sumrec(a-1);
    }
}