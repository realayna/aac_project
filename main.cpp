#include <algorithm>
#include <chrono>
#include <cassert>
#include <iostream>
#include <random>
#include "insert.h"
#include "mergesort.h"
#include "quick.h"
#include "heapsort.h"

int main()
{
    using std::chrono::nanoseconds;
    using std::chrono::steady_clock;

    constexpr int max_size = 15000;
    constexpr int step = 100;
    constexpr int times = 100;
    std::uniform_int_distribution<int> dist(-max_size, max_size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::cout << "size insertion_sort sorted_insertion_sort quick_sort sorted_quicksort\n";
    for (int len = step; len < max_size; len += step)
    {

        int *arr = new int[len];
        int *arr_q = new int[len];
        nanoseconds s_quick(0);
        nanoseconds quick(0);
        nanoseconds heap(0);
        nanoseconds merge(0);
        nanoseconds total_i(0);
        nanoseconds ins_s(0);
        

        for (int i = 0; i < times; i++)
        {
            for (int i = 0; i < len; i++)
            {
                arr[i] = dist(gen);
            }

            std::copy(arr, arr + len, arr_q); // copying array for otther sorts

            auto begin = steady_clock::now();
            insert_sort(arr, len);
            auto end = steady_clock::now();
            total_i += end - begin;

            std::sort(arr, arr + len);
            auto begin_i = steady_clock::now();
            insert_sort(arr, len);
            auto end_i = steady_clock::now();
            ins_s += end_i - begin_i;

            auto begin_q = steady_clock::now();
            quicksort(arr_q, 0, len - 1);
            auto end_q = steady_clock::now();
            quick += end_q - begin_q;

            std::sort(arr_q, arr_q + len);
            auto begin_qs = steady_clock::now();
            quicksort(arr_q, 0, len - 1);
            auto end_qs = steady_clock::now();
            s_quick += end_qs - begin_qs;
        }
        std::cout
            << len << " "

            << total_i.count() / times << " "
           <<  ins_s.count() / times << " "
           << quick.count() / times << " "
           <<s_quick.count()/times<<std::endl;

        delete[] arr;
    }

    return 0;
}