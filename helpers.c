/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       

#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search (int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    if (n > 0)
    {
        int i = n/2, low = 0, high = 0, dim = 0;
        if (value == values[i])
            return true;
        else if (value < values[i])
        {
            low = 0;
            high = i;
        }
        else
        {
            low = i + 1;
            high = n;
        }
        
        dim = high - low;
        int sub_values[dim];
        
        for (int j = 0; j < dim; j++)
        {
            sub_values[j] = values[low + j];
        }
        
        return search(value, sub_values, dim);
    }
        
    
    return false;
}

bool search_linear(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    if (n < 0)
        return false;
    
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
            return true;
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // Implemented insertion so in the best case (Omega)
    //it will run once through the array
    int i, j, temp;
    
    for (i = 0; i < n; i++)
    {
        temp = values[i];
        for (j = i; j >= 0; j--)
        {
            if (temp < values[j])
            {
                values[j+1] = values[j];
                values[j] = temp;
            }
        }
    }    
    
    // for (i = 0; i < n; i++)
    // {
    //     printf("DEBUG: %d: %d\n", i, values[i]);
    // }
    
    return;
}