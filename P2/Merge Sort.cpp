
#include <iostream>
using namespace std;

// function to merge two subarrays
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // create temporary arrays
    int L[n1], R[n2];
    
    // copy data to temporary arrays
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
        
    // merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    // copy the remaining elements of L[], if there are any
    while(i < n1)
        arr[k++] = L[i++];
    
    // copy the remaining elements of R[], if there are any
    while(j < n2)
        arr[k++] = R[j++];
}

// function to perform merge sort
void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);1
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // call mergeSort function
    mergeSort(arr, 0, n-1);
    
    // print the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}
