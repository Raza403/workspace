#include <stdio.h>

#include <cs50.h>

int main (void)

{
  
    int minutes, bottels;
    
    do                                                  //Do while loop for protection of negative input.
    {
    
         printf ("Your shower takes how many minutes.\n");

    minutes = GetInt ();
    
   }
   
   while (minutes<0);
    
    bottels = minutes * 12;
    
        printf (" You use %d bottels\n ", bottels);
    
}