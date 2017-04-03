#include <stdio.h>
#include <cs50.h>


int main()

{   
    int values[12];
   for (int j=0;j<12;j++)
    {
        values[j]=GetInt();
    }
  int n=12;
 
    //implementing bubble sort
    //checking swap is true
    int swap=true;
    while (swap==true)
    {
        int temp;
        for (int i=0;i<n-1;i++)
        {
            swap=false;
            if (values[i]>values[i+1])
            {
                temp=values[i+1];
                values[i+1]=values[i];
                values[i]=temp;
                swap=true;
                printf("%i\n",values[i]);
            }
        }
    
    
    }
  
    return 0;
}