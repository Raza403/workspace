#include <stdio.h>

#include <cs50.h>

int main (void)

{
    
    int height, space, hash;                                             //height of pyramid
    
    do
    {
        printf ("Please give height of the half Peramid from 1 to 23\n");
        
        height = GetInt();
        
    }
    while (height <= 0 || height >23);
    

    for (int i=0; i<height; i++)                                //Printing spaces
    {
    
        for (space=0; space<height-i-1; space++)
        
       {
           printf (" ");
           
       }
        for (hash=0; hash<i+2; hash++)                      //Printing hash    
        {
            printf("#");
        }
        printf ("\n");
}
}