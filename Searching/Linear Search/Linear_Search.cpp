/* Linear Search Implementation
 * @author yoonbot
 * 07/23/2021
 */

#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

/* Addditional functions used throughout the program */
int linearSearch(int*, int, int);

/* Driver Program */
int main(){
    int *arr;
    int key;
    int size;
    double elapsed = 0;

    cout << "Enter array size: ";
    cin >> size;

    arr = new int[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter element to be searched: ";
    cin >> key;

    /* Start timer */
    clock_t start = clock();
    int result = linearSearch(arr, size, key);

    (result == -1) ? cout << "Element is not present in array\n"
                   : cout << "Element is present at index " << result << "\n";

    /* End timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printf("Linear Search Completed in %.6lf seconds\n", elapsed);
    delete [] arr;
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

