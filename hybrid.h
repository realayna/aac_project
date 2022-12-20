#pragma once
#include "quick.h"
#include "insert.h"
#include <iostream>
#include <algorithm>

void hybridsort(int *arr, int f, int l)
{

    while (f < l)
    {
        if (l - f < 45)
        {
            insert_sort(arr, l);
            break;
        }

        else
        {
            int pivot = partition(arr, f, l);

            if (pivot - f < l - pivot)
            {
                hybridsort(arr, f, pivot-1);
                f = pivot + 1;
            }

            else
            {
                hybridsort(arr,pivot +1, l );
                l = pivot - 1;

            }
        }
    }

}
