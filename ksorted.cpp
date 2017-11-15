#include <cstdlib>
#include <iostream>
#include "minheap.h"

using namespace std;

int sortK(int arr[], int n, int k)
{
    // Create a Min Heap of first (k+1) elements from
    int *harr = new int[k+1];
    for (int i = 0; i<=k && i<n; i++) 
        harr[i] = arr[i];
    MinHeap hp(harr, k+1);
 
    // i is index for remaining elements in arr[] and ti
    // is target index of for current minimum element in
    // Min Heap 'hp'.
    for(int i = k+1, ti = 0; ti < n; i++, ti++)
    {
        // If there are remaining elements place
        // root of heap at target index and add arr[i]
        // to Min Heap
        if (i < n)
            arr[ti] = hp.replaceMin(arr[i]);
 
        // Otherwise place root at its target index and
        // reduce heap size
        else
            arr[ti] = hp.extractMin();
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
       cout << arr[i] << " ";
   cout << endl;
}

int main()
{

	int size;
	int k;
	int n;
    cout<< "How many elements in the array?" << endl;
    cin >> size;
	
	int arr[size];
	srand((unsigned)time(0)); 
     
    for(int i=0; i<size; i++){ 
        arr[i] = (rand()%100)+1; 
         
        cout << arr[i] << endl;
 	}
	

	n = sizeof(arr)/sizeof(arr[0]);

	cout << "The unsorted array is:"<< endl;
    printArray (arr, n); 
	
    cout<< "Select k for sorting" << endl;
    cin >> k;
    
    sortK(arr, n, k);
 
    cout << "The sorted array with k="<<k<<" is:"<< endl;
    printArray (arr, n);
 	
    return 0;
}

