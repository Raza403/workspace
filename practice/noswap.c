# include <stdio.h>
int swap(int a,int b);
int main (void)
{
    int x = 1;
    int y = 2;
    printf ("swapping\n");
    swap (x,y);
    printf ("%i  %i\n", x,y);
    
}
int swap (int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    return a,b;
}