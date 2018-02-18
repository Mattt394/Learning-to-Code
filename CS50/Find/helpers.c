/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n<0)
    {
        return false;
    }

    //initialise ints
    int mid;
    int end=n-1;
    int beg=0;
    //begin binary search
    while (end-beg>0)
    {
        //find middle
        mid=(beg+end)/2;
        //check middle
        if (values[mid] == value)
        {
            return true;
        }
        //initialise left part
        else if (value>values[mid])
        {
            beg = mid+1;
        }
        //initialise right part
        else
        {

            end = mid-1;
        }
    }
    //add case where its got down to one square array because code can't handle it for some reason ;;
    if (end==beg && value == values[end])
    {
        return true;
    }
    else
    {
        return false;
    }

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    //find max
    int maxi=values[0];
    for (int i=0; i<n; i++)
    {
        if (maxi<values[i])
        {
            maxi=values[i];
        }
    }
    int arr[maxi];
    for (int i=0; i<maxi; i++)
    {
        arr[i] = 0;
    }
    //count the values
    for (int i=0; i<n; i++)
    {
        arr[values[i]]++;

    }

    //put back in array
    int j=0;
    for (int i=0; i<=maxi; i++)
    {
        int temp = arr[i];
        while (temp>0)
        {
            //eprintf("%i: %i", values[j], arr[i]);
            values[j] = i;
            temp--;
            j++;
            if (j>n+1)
            {
                eprintf("Shouldn't get to here %i", j);
                break;
            }
            //eprintf("values %i: arr %i, j= %i", values[j], arr[i], j);
        }

    }










/*    int min;
    for (int i=0; i<n-2; i++)
    {
        min = values[i];
        for (int j=0;j<n-1;j++)
        {
            if (values[j]<min)
            {
                min = values[j];
            }
        }

        if (min!=values[i])
        {
            values[i] = min;
        }
*/
    return;
}
