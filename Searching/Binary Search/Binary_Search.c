/* Binary Search Implementation
 * @author yoonbot
 * 07/23/2021
 */

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

/* Additional functions used throughout the program */
int binarySearch(int*, int, int, int);

/* Driver Program */
int main(void)
{   
    int *arr;
    int x;
    int n;
    double elapsed = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to be searched: ");
    scanf("%d", &x);
    
    /* Start timer */
    clock_t start = clock();
    int result = binarySearch(arr, 0, n - 1, x);

    (result == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d\n",
                            result);
    
    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printf("Binary Search Completed in %.6lf seconds\n", elapsed);
    free(arr);
    return 0;
}

/* Binary Search Algorithm */
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}


