/* Bubble Sort Implementation
 * @author yoonBot
 * 06/04/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Additional functions used throughout the program */
void swap(int *, int*);
void bubble(int *, int);
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
    bubble(array, size);

    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printArray(array, size);
    printf("Bubble Sorting Completed in %.6lf seconds\n", elapsed);
    free(array);

    return 0;
}

/* Swap Function */
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/* Bubble Sort Algorithm */
void bubble(int *arr, int size){
    int i, j, minimum;

    for (i = 0; i < size - 1; i++)
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
            // Bubble Sort compares only two elements next to each other
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

/* default print function for all sorting programs */
void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

