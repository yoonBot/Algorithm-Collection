/* Selection Sort Implementation
 * @author yoonBot
 * 06/03/2021
 */

#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

/* Additional functions used throughout the program */
void swap(int *, int*);
void selection(int *, int);
void printArray(int *, int);

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
    selection(array, size);

    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printArray(array, size);
    printf("Selection Sorting completed in %.6lf seconds\n", elapsed);
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
        cout << array[i] << " ";
    cout << "\n";
}

