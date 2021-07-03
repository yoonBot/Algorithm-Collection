/* Merge Sort Implementation 
 * @author yoonBot
 * 05/28/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Additional functions used throughout the program */
void merge(int *, int, int, int);
void mergeSort(int *, int, int);
void printArray(int *, int);

/* Driver Program */
int main(){
    int *array;
    int size;
    double elapsed = 0;

    printf("Enter array size: ");
    scanf("%d", &size);

    array = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    /* Start timer */
    clock_t start = clock();
    mergeSort(array, 0, size - 1);

    /* End timer */
    elapsed += (double) (clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printArray(array, size);
    printf("Merge Sorting Completed in %.6lf seconds\n", elapsed);
    free(array);
    
    return 0;
}

/* Merge Sort Algorithm */
void merge(int array[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int Left[n1], Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = array[l + i];
    for (int j = 0; j < n2; j++)
        Right[j] = array[m + 1 + j];

    int i = 0, j = 0;  // initial index of the two subarrays
    int k = l;         // initial index of merged subarray

    while (i < n1 && j < n2){
        if (Left[i] <= Right[j]){
            array[k] = Left[i];
            i++;
        }
        else{
            array[k] = Right[j];
            j++;
        }
        k++;
    }
    
    while (i < n1){
        array[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2){
        array[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2; // same thing as (l + r) / 2 but to prevent overflow
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

/* default print function for all sorting programs */
void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}


