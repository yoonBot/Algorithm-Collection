/* Radix Sort Implementation
 * @author yoonBot
 * 07/27/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Additional functions used throughout the program */
int getMax(int*, int);
void countSort(int*, int, int);
void radixSort(int*, int);
void printArray(int*, int);

/* Driver Program */
int main(){
    int *arr;
    int size;
    double elapsed = 0;

    printf("Enter array size: ");
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    /* Start timer */
    clock_t start = clock();
    radixSort(arr, size);

    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printArray(arr, size);
    printf("Radix Sorting completed in %.6lf seconds\n", elapsed);

    free(arr);
    return 0;
}

/* returns the max value of an array */
int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

/* supplementary count sort algorithm */
void countSort(int arr[], int n, int exp){
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

/* main radix sort algorithm */
void radixSort(int arr[], int n){
    
    // find the max value to know number of digits
    int m = getMax(arr, n);
    
    // do counting sort for every digit
    // exp = exponent, as it is multiplied by 10 to move through
    // digits place
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

/* default print function for all sorting algorithms */
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

