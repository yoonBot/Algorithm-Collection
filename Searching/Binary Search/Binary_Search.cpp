/* Binary Search Implementation
 * @author yoonbot
 * 07/23/2021
 */

#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

/* Additional functions used throughout the program */
int binarySearch(int*, int, int, int);

/* Driver Program */
int main(void){
    int *arr;
    int x;
    int n;
    double elapsed = 0;

    cout << "Enter array size: ";
    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to be searched: ";
    cin >> x;

    /* Start timer */
    clock_t start = clock();
    int result = binarySearch(arr, 0, n - 1, x);

    (result == -1) ? cout << "Element is not present in array\n" 
                   : cout << "Element is present at index " << result << "\n";

    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printf("Binary Search Completed in %.6lf secnods\n", elapsed);
    delete [] arr;

    return 0;
}

/* Binary Search Algorithm */
int binarySearch(int arr[], int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller then mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present 
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array;
    return -1;
}


