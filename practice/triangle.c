#include <cs50.h>
#include <stdio.h>

bool triangle (float a, float b, float c); //Declaration of function

int main (void)

{
    
    printf ("Give me three sides of triangle!\n");
    
    float x = GetFloat ();
    float y = GetFloat ();
    float z = GetFloat ();
    bool tf= triangle (x,y,z); // Calling function
    if (tf==true)
    {printf ("True\n");
        
    }
    else if (tf==false)
    {
        printf ("false\n");
    }
   // printf ("%d", tf); // I want to know how to print value return by triangle function(true/false)

}
bool triangle (float a,float b, float c) // Defining function
{
    if ((a<1) || (b<1) || (c<1)) //Condition
        return false;
    
    else if ((a+b<c)||(a+c<b)||(b+c<a)) // Second condition
    return false;
        
else
    
   { return true;// if both conditions are false then return true
}}