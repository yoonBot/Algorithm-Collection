/* Linear Search Implementation
 * @author yoonbot
 * 07/23/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Additional functions used throughout the program */
int linearSearch(int*, int, int);

/* Driver Program */
int main(){
    int *arr;
    int key;
    int size;
    double elapsed = 0;

    printf("Enter array size: ");
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to be searched: ");
    scanf("%d", &key);

    /* Stsrt timer */
    clock_t start = clock();
    int result = linearSearch(arr, size, key);

    (result == -1) ? printf("Element is not present in array\n") 
                   : printf("Element is present at index %d\n", result);

    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printf("Linear Search Completed in %.6lf seconds\n", elapsed);
    free(arr);
    return 0;
}

/* Linear Search Algorithm */
int linearSearch(int arr[], int n, int x){
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

