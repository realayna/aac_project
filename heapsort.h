#pragma once
#include <iostream>
#include <algorithm>
void heapify (int*arr, int n, int m)
{
    int max = m;
    int l = 2*m+1; //left
    int r = 2*m + 2; //right


    if (l < n && arr[l] > arr[max])
        max = l;
    if (r < n && arr[r] > arr[max])
        max = r;

    if (max!=m)
    {
        
        
        std::swap(arr[m], arr[max]);
        heapify(arr, n, max);

    }


}

void heapsort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i =n-1; i>0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        
    }
}
