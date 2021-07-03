/* Selection Sort Implementation
 * @author yoonBot
 * 06/03/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Additional functions used throughout the program */
void swap(int *, int *);
void selection(int *, int);
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
    selection(array, size);

    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printArray(array, size);
    printf("Selection Sorting Completed in %.6lf seconds\n", elapsed);
    free(array);

    return 0;
}
/* Swap Function */
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/* Selection Sort Algorithm */
void selection(int *arr, int size){
    int i, j, minimum;

    // Traverse through the array one by one
    for (i = 0; i < size - 1; i++){
        minimum = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[minimum])
                minimum = j;

        // Swap the found minimum array value with the first array value
        swap(&arr[minimum], &arr[i]);
    }
}

/* default print function for all sorting programs */
void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}



