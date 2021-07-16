/* Quick Sort Implementation 
 * @author yoonBot
 * 07/16/2021
 */

#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

/* Additional functions used throughout the program */
void swap(int*, int*);
int partition(int*, int, int);
void quickSort(int*, int, int);
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
    quickSort(array, 0, size - 1);

    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printArray(array, size);
    printf("Quick Sorting Completed in %.6lf seconds\n", elapsed);
    delete [] array;

    return 0;
}

/* Swap function */
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/* partition the array */
int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* Quick Sort Algorithm */
void quickSort(int *arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* default print function for all sorting programs */
void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


