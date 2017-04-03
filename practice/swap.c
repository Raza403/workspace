#include <stdio.h>
# include <stdlib.h>
void swap (int* x,int* y);
int main (void)
{
    int a = 1;
    int b = 2;
    printf("value of a and b is %i,%i respectively\n", a,b);
    printf ("Swapping!\n");
    swap (&a,&b);
   printf("value of a and b is %i,%i respectively\n", a,b);
   
    
}

void swap (int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
     free (temp);
}