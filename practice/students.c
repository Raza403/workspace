# include <stdio.h>
# include <cs50.h>
# include "struct.h"
# define STD 3
int main (void)
{
    students students[STD];
    int i=0;
    for (i=0;i<STD;i++)
    
    {
        printf("enter name\n");
        students[i].name= GetString();
        printf("Adress\n");
        students[i].house = GetString();
        
    }
        FILE *file= fopen ("students.csv", "w");
        if (file!=NULL)
        {
            for (int n=0; n<STD; n++)
            {
                fprintf (file, "%s,%s\n", students[n].name, students[n].house);
                
            }
            fclose (file);
        }
    
}