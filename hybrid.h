#pragma once
#include "quick.h"
#include "insert.h"
#include <iostream>
#include <algorithm>

void hybridsort(int *arr, int f, int l)
{
    
    if (l - f  < 65)
    {
        insert_sort(arr, l, f);
       
    }

    else
    {
        int pivot = partition(arr, f, l);
        hybridsort(arr, f, pivot-1);
        hybridsort(arr,pivot +1, l );
    }

   

}