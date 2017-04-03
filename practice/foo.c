#include <stdio.h>
#include <cs50.h>
int main (void)
{
    int foo[10];
    
    printf("%p, %p, %p\n", foo, &foo, &foo[0]);
}