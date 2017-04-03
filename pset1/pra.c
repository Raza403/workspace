#include <stdio.h>
#include<cs50.h>
#include<math.h>
int main (void)
{
    float dlr, cents;
    int counter=0;
do
{
    printf ("num\n");
    dlr=GetFloat ();
    
}

while (dlr<0);

cents=round(dlr*100);

while (cents>=25)
{

cents=cents-25;

counter++;
}

printf ("%d\n", counter);


}