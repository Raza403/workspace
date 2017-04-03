# include <stdio.h>
# include <cs50.h>
#include <stdlib.h>
# include "struct.h"
# define STD 3
int main (void)
{
    student students[STD];
    int i=0;
    for (i=0;i<STD;i++)
    
    {
        printf("enter name\n");
        students[i].name= GetString();
        printf("Adress\n");
        students[i].house = GetString();
        
    }
        for (int y=0;y<STD;y++)
        {
        printf("students name is %s lives in %s\n\n", students[y].name, students[y].house);
        }
        for (int x=0;x<STD;x++)
    {    
        free (students[x].name);
        free (students[x].house);
        
    }
    
}