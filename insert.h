#ifndef INSERT_H
#define INSERT_H

#include <iostream>

void insert_sort(int *arr, int len, int s = 0)
{
    int now;
    int j;

    for (auto i=s + 1; i<=len; i++)
    {
        int now = arr[i];
        int j = i-1;

        while ( j>= s && now< arr[j])
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1]=now;

    }
}
#endif  // INSERT_H
