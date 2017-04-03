#include <stdio.h>
#include <cs50.h>
void swap (int* x,int* y);
int main (void)
{
    printf("Enetr first int\n");
    int a = GetInt();
    printf("Enetr second int int\n");
    int b = GetInt();
    printf ("Swapped values\n");
    swap(&a,&b);
    printf ("%i\n", a);
    printf("%i\n", b);
    return 0;
}

void swap (int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}