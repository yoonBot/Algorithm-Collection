/* Bubble Sort Implementation
 * @author yoonBot
 * 07/04/2021
 */

#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

/* Additional functions used throughout the program */
void swap(int*, int*);
void bubble(int*, int);
void printArray(int*, int);

/* Driver Program */
int main(){
    int *array;
    int size;
    double elapsed = 0;

    cout << "Enter array size: ";
    cin >> size;

    array = new int[size];

    for (int i = 0; i < size; i++)
        cin >> array[i];

    /* Start timer */
    clock_t start = clock();
    bubble(array, size);

    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printArray(array, size);
    printf("Bubble Sorting completed in %.6lf seconds\n", elapsed);
    free(array);

    return 0;
}

/* Swap function */
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
        for (j = 0; j < size - 1; j++)
            // Bubble Sort compares only two elements next to each other
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

/* default print function for all sorting programs */
void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "\n";
}

