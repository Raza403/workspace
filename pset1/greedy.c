#include <stdio.h>

#include <cs50.h>

#include <math.h>

int main(void)

{
    float dlr, cents;
    
    int counter=0;
    
    do
    {
        printf ("Enter the amount\n");
        
       dlr= GetFloat ();
        
    }
    
    while (dlr<0);                          //Protection from non float input.

cents=round(dlr*100);                       //converting dollars into cents and rounding off float.

while (cents>=25)
{
cents=cents-25;

counter++;                                  //For counting loop cycles.
}

while (cents>=10)
{
    cents=cents-10;
    counter++;
}

while (cents>=5)
{
    cents=cents-5;
    counter++;
}

while (cents>=1)
{
    cents=cents-1;
    counter++;
}

printf("%d\n", counter);

}