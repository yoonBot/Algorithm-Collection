/* Insertion Sort Implementation
 * @author yoonBot
 * 05/29/2021
 */

#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

/* Additional Functions used throughout the program */
void insertion(int *, int);
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
    insertion(array, size);

    /* End timer */
    elapsed += (double) (clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printArray(array, size);
    printf("Insertion Sorting Completed in %.6lf seconds\n", elapsed);
    delete [] array;

    return 0;
}

/* Insertion Sort Algorithm */
void insertion(int array[], int size){
    for (int i = 1; i < size; i++){
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

/* default print function for all sorting programs */
void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "\n";
}
