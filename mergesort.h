#pragma once
void merge(int *arr, int l, int mid, int r)
{
    int left = mid - l + 1;
    int right = r - mid;
    int* larr = new int [left];
    int *rarr = new int [left];

    for (int i = 0; i < left; i++)
	{
		larr[i] = arr[l + i];
	}
	for (int j = 0; j < right; j++)
	{
		rarr[j] = arr[mid + 1 + j];
	}

   int i=0;
   int j=0;
   int k=l;

   while (i<left && j < right)
   {
     if (larr[i]<=rarr[j])
     {
        arr[k]=larr[i];
        i++;
     }
     else
     {
        arr[k]=rarr[j];
        j++;
     }
     k++;

    while (j < right)
    {
        arr[k]=rarr[j];
        j++;
        k++;

    }

   }

}




void mergeSort(int *arr, int l, int r)
{
  
if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 

}