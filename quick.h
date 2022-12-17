#ifndef QUICK_H
#define QUICK_H
#include <iostream>
#include <algorithm>
int partition(int *arr, int f, int l)
{
    int pivot = arr[f];
    int pi = f + 1;
    int temp;
    for (auto i = f + 1; i <= l; i++)
    {
        if (arr[i] < pivot)
        {
            temp = arr[pi];
            arr[pi] = arr[i];
        }
        pi++;
    }
    arr[f] = arr[pi - 1];
    arr[pi - 1] = pivot;

    return pi - 1;
}

void quicksort(int *arr, int f, int l)
{
    int pi;
    if (f < l)
    {
        pi = partition(arr, f, l);
        quicksort(arr, f, pi - l);
        quicksort(arr, pi + 1, l);
    }
}

#endif // QUICK_H
