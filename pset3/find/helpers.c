/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
#include <stdio.h>       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{   //implementing Binary search
    int first=0;//first element of array
    int last=n-1;//last element of array
    if (n<=0)//if array size is 0 return false
    {
        return false;
    }
    
    while (last>=first)//when last element of array is equel to or greater than first 
    {
        
            if (last==first)//when array is of single element check if that element is needle
        {
            if (values[n-1]==value)
            return true;
        }
        if (last==1)//if there is only two elements in the array check both if needle is among them
        {
            if (values[0]==value)
        {
            return true;
        }
        if (values[1]==value)
        {
            return true;
        }
    }
        int center=(first+last)/2;//defining center value
        if (values[center]==value)//if center if array is needle then rerurn true
        {
            return true;
        }
        if (values[center]>value)//when center is greater than needle see left side of the array
        {
            last=center-1;
        }
        if (values[center]<value)//when center value is less than needle search in right side
        {
            first=center+1;
        }
    }
        
    //else return false
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    //implementing bubble sort
   // checking swap is true
   for (int g=0;g<n;g++)
   {
    int swap=true;
    while (swap==true)
    {
        //temporary memory for swapping
        int temp;
        //second for loop making it O(n)^2
        for (int i=0;i<n-1;i++)
        {
            swap=false;
            //checking if any swap is needed or array is sorted
            if (values[i]>values[i+1])
            {
                //implementation of bubble sort.
                temp=values[i+1];
                values[i+1]=values[i];
                values[i]=temp;
                swap=true;
            }
        }}}
    return;
    
}