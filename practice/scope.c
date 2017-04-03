#include <stdio.h>
#include <cs50.h>
int increment (int a);
int main (void)
{
    int x=1;
   x= increment (x);
    printf ("%i\n",x);
}
int increment (int a)
{
    a++;
    return a;
}