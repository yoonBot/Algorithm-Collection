/* Multiplying 2 matrices
 * @author yoonBot
 * 06/04/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Additional functions used throughout the program */
void SquareMatrixMult(int*, int, int*, int*);
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
    while (col1 != row2){
        printf("Error! col1 and row2 sizes must be equivalent!\n");
        scanf("%d", &row2);
    }
    printf("Enter Matrix #2 col: ");
    scanf("%d", &col2);   
    
    mat2 = (int*)malloc(row2 * col2 * sizeof(int));

    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++){
            printf("Enter element at pos: %d,%d : ", i, j);
            scanf("%d", (mat2 + i * col2 + j));
        }
    
    /* Create Resulting Matrix */
    // if a x b and b x c, then a x c for final. 
    res = (int*)malloc(row1 * col2 * sizeof(int));
    
    /* Display input */
    printf("Matrix #1:\n");
    printMatrix(mat1, row1, col1);
    printf("Matrix #2:\n");
    printMatrix(mat2, row2, col2);
    printf("Result Matrix:\n");
    
    /* Start Clock */
    clock_t start = clock();
        // we only need either row1 or col2, since both sizes must be equal anyways
    SquareMatrixMult(mat1, row1, mat2, res);
    printMatrix(res, row1, col2);

    /* End Timer */
    elapsed += (double) (clock() - start);
    elapsed /= CLOCKS_PER_SEC;
    
    /* print */
    printf("Computation Completed in %.6lf seconds\n", elapsed);
    
    free(mat1);
    free(mat2);
    free(res);

    return 0;
}

/* Multiplying Two Matrixes */
void SquareMatrixMult(int *mat1, int row1, int *mat2, int *res){
    int i, j, k;
    for (i = 0; i < row1; i++)
        for (j = 0; j < row1; j++){
            //res[i][j] = 0;
            *(res + i * row1 + j) = 0;
            for (k = 0; k < row1; k++)
                //res[i][j] += mat1[i][k] * mat2[k][j];
                *(res + i * row1 + j) += *(mat1 + i * row1 + k) * *(mat2 + k * row1 + j);
        }
}

/* Print Matrixes */
void printMatrix(int *mat, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            printf("%d ", *(mat + i * col + j));
        printf("\n");
    }
}


