#include <algorithm>
#include <chrono>
#include <cassert>
#include <iostream>
#include <random>
#include "insert.h"
#include "mergesort.h"
#include "quick.h"
#include "heapsort.h"
#include "hybrid.h"

int main()
{
    using std::chrono::nanoseconds;
    using std::chrono::steady_clock;

    constexpr int max_size = 100;
    constexpr int step = 5;
    constexpr int times = 100;
    std::uniform_int_distribution<int> dist(-max_size, max_size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::cout << "size insertionsort  quicksort  mergesort heapsort hybrid\n";
    for (int len = step; len < max_size; len += step)
    {

        int *arr = new int[len];
        int *arr_i = new int[len]; //insertion
        int *arr_q = new int[len]; //array for quicksort
        int *arr_m = new int[len]; //merge
        int *arr_h = new int[len]; //heap
        int *arr_b = new int [len]; //hybrid

        //nanoseconds s_quick(0);
        nanoseconds quick(0);
        nanoseconds heap(0);
        nanoseconds merge(0);
        nanoseconds total_i(0);
        nanoseconds hybrid(0);
        //nanoseconds ins_s(0);
        

        for (int i = 0; i < times; i++)
        {
            for (int i = 0; i < len; i++)
            {
                arr[i] = dist(gen);
            }

            std::copy(arr, arr + len, arr_i); // copying array for otther sorts
            std::copy(arr, arr + len, arr_q); 
            std::copy(arr, arr + len, arr_m); 
            std::copy(arr, arr + len, arr_h); 
            std::copy(arr, arr + len, arr_b); 

            auto begin = steady_clock::now();
            insert_sort(arr_i, len - 1);
            auto end = steady_clock::now();
			assert(std::is_sorted(arr_i, arr_i+len));
            total_i += end - begin;

            // std::sort(arr_i, arr_i + len);
            // auto begin_i = steady_clock::now();
            // insert_sort(arr_i, len);
            // auto end_i = steady_clock::now();
            // ins_s += end_i - begin_i;

            auto begin_q = steady_clock::now();
            quicksort(arr_q, 0, len - 1);
            auto end_q = steady_clock::now();
			assert(std::is_sorted(arr_q, arr_q+len));
            quick += end_q - begin_q;

            // std::sort(arr_q, arr_q + len);
            // auto begin_qs = steady_clock::now();
            // quicksort(arr_q, 0, len - 1);
            // auto end_qs = steady_clock::now();
            // s_quick += end_qs - begin_qs;

            
            auto begin_m = steady_clock::now();
            mergeSort(arr_m, 0, len - 1);
            auto end_m = steady_clock::now();
			assert(std::is_sorted(arr_m, arr_m+len));
            merge += end_m - begin_m;

            auto begin_h = steady_clock::now();
            heapsort(arr_h, len);
            auto end_h = steady_clock::now();
			assert(std::is_sorted(arr_h, arr_h+len));
            heap += end_h - begin_h;

            auto begin_b = steady_clock::now();
            hybridsort(arr_b, 0, len - 1);
            auto end_b = steady_clock::now();
			assert(std::is_sorted(arr_b, arr_b+len));
            hybrid += end_b - begin_b;

        }
        std::cout
           << len << " "
           << total_i.count() / times << " "
           //<<  ins_s.count() / times << " "
           << quick.count() / times << " "
          // <<s_quick.count()/times<<" "
           <<merge.count()/times<<" "
           <<heap.count()/times<<" "
           <<hybrid.count()/times<<std::endl;

        delete[] arr;
        delete [ ]arr_i;
        delete [ ]arr_q;
        delete [] arr_m;
        delete [ ]arr_b;
       delete [] arr_h;

    }

    return 0;
}
