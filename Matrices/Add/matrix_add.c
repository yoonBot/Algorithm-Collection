/* Adding 2 matrices
 * @author yoonBot
 * 07/19/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Additional functions used throughout the program */
void AddMatrix(int*, int, int*, int*);
void printMatrix(int*, int, int);

/* Driver Program */
int main(){
    int row1, col1, row2, col2;
    int *res, *mat1, *mat2;
    double elapsed;
    
    /* Create Input Matrix #1 */
    printf("Enter Matrix #1 row: ");
    scanf("%d", &row1);
    printf("Enter Matrix #1 col: ");
    scanf("%d", &col1);

    mat1 = (int*)malloc(row1 * col1 * sizeof(int));

    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++){
            printf("Enter element at pos: %d,%d : ", i, j);
            scanf("%d", (mat1 + i * col1 + j));
        }
    
    /* Create Input Matrix #2 */
    printf("Enter Matrix #2 row: ");
    scanf("%d", &row2);
    while (row1 != row2){
        printf("Error! row1 and row2 sizes must be equivalent!\n");
        scanf("%d", &row2);
    }
    printf("Enter Matrix #2 col: ");
    scanf("%d", &col2);
    while(col1 != col2){
        printf("Error! col1 and col2 sizes must be equivalent!\n");
        scanf("%d", &col2);
    }

    mat2 = (int*)malloc(row2 * col2 * sizeof(int));

    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++){
            printf("Enter element at pos: %d,%d : ", i, j);
            scanf("%d", (mat2 + i * col2 + j));
        }

    /* Create Resulting Matrix */
    // To perform addition, all dimensions of both matrixes must be equal
    res = (int*)malloc(row2 * col2 * sizeof(int));

    /* Display input Matrices */
    printf("Matrix #1:\n");
    printMatrix(mat1, row1, col1);
    printf("Matrix #2:\n");
    printMatrix(mat2, row2, col2);
    printf("Result Matrix:\n");

    /* Start Clock */
    clock_t start = clock();
    AddMatrix(mat1, row1, mat2, res);
    printMatrix(res, row1, col2);

    /* End Timer */
    elapsed += (double)(clock() - start);
    elapsed /= CLOCKS_PER_SEC;

    /* print */
    printf("Computation Completed in %.6lf seconds\n", elapsed);

    free(mat1);
    free(mat2);
    free(res);

    return 0;
}

/* Adding Two Matrices */
void AddMatrix(int *mat1, int row1, int *mat2, int *res){
    int i, j;
    
    for (i = 0; i < row1; i++)
        for (j = 0; j < row1; j++)
            // res[i][j] = mat1[i][j] + mat2[i][j]
            *(res + i * row1 + j) = *(mat1 + i * row1 + j) + *(mat2 + i * row1 + j);
}

/* Print Matrices */
void printMatrix(int *mat, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            printf("%d ", *(mat + i * col + j));
        printf("\n");
    }
}




