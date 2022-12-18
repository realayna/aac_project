#ifndef QUICK_H
#define QUICK_H
#include <iostream>
#include <algorithm>
int partition(int *arr, int f, int l)
{
    int pivot = arr[f];
    int pi = f;
    int temp;
    for (auto i = f + 1; i <= l; i++)
    {
        if (arr[i] < pivot)
        {
			pi++;
            temp = arr[pi];
            arr[pi] = arr[i];
			arr[i] = temp;
        }
    }
    arr[f] = arr[pi];
    arr[pi] = pivot;

    return pi;
}

void quicksort(int *arr, int f, int l)
{
    int pi;
    if (f < l)
    {
        pi = partition(arr, f, l);
        quicksort(arr, f, pi - 1);
        quicksort(arr, pi + 1, l);
    }
}

#endif // QUICK_H
