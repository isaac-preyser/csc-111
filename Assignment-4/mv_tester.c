/* 17_mv_multiplyII/main.c
   CSC 111 - Fall 2023 - Assignment 4


   B. Bird - 2023-10-14
*/


#include <stdio.h>
#include <math.h>
#include "matrix_and_vector.h"


//print_matrix(rows, columns, M)
//Print the contents of the matrix M
static void print_matrix(int rows, int columns, double M[rows][columns]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++)
            printf("%7.2f ", M[i][j]);
        printf("\n");
    }
}
    
//print_column_vector(size, V)
//Print the contents of the vector V as a column (analogous to a 1 x size matrix)
static void print_column_vector(int size, double V[size]){
    for (int i = 0; i < size; i++)
        printf("%7.2f\n", V[i]);
}

// invalidate_vector(size, V)
// Set every element of V to infinity
static void invalidate_vector(int size, double V[size]){
    int i;
    for (i = 0; i < size; i++)
            V[i] = INFINITY;
}

int main(){

    double M1[4][3] = {	{0, 0, 4},
                        {3, 3, 3},
                        {2, 2, 2},
                        {1, 1, 1} };

    double M2[5][3] = {	{0.25, 0.5, 0.75},
                        {0.33, 0.66, 1.0},
                        {-1,      1,  -1},
                        {0,       1,   0},
                        {0,       0,  -1} };

    double M3[3][4] = {	{1, 1, 1, 1},
                        {0, 2, 2, 2},
                        {0, 0, 3, 3} };

    double M4[3][5] = {	{0.5,   0.25,  0.125,  0.0625},
                        {-0.5, -0.25, -0.125, -0.0625},
                        {1.0,    0.8,    0.6,     0.4} };

    double V1[3] = {1.11, 1.16, 1.87};
    double V2[4] = {4, 9, 16, 25};

    double Z[100];
    
    printf("Testing matrix_vector_multiply:\n");
    printf("Input matrix M1:\n");
    print_matrix(4, 3, M1);
    printf("Input matrix M2:\n");
    print_matrix(5, 3, M2);
    printf("Input matrix M3:\n");
    print_matrix(3, 4, M3);
    printf("Input matrix M4:\n");
    print_matrix(3, 4, M4);
    printf("\n");
    printf("Input Vector V1:\n");
    print_column_vector(3, V1);
    printf("Input Vector V2:\n");
    print_column_vector(4, V2);
    printf("\n");
    
    printf("M1 * V1 (fifth entry should be inf):\n");
    invalidate_vector(100, Z);
    matrix_vector_multiply(4, 3, M1, V1, Z);
    print_column_vector(5, Z);
    printf("\n");
     
    printf("M2 * V1 (sixth entry should be inf):\n");
    invalidate_vector(100, Z);
    matrix_vector_multiply(5, 3, M2, V1, Z);
    print_column_vector(6, Z);
    printf("\n");
    
    printf("M3 * V2 (fourth and fifth entries should be inf):\n");
    invalidate_vector(100, Z);
    matrix_vector_multiply(3, 4, M3, V2, Z);
    print_column_vector(5, Z);
    printf("\n");
    
    printf("M4 * V2 (fourth and fifth entries should be inf):\n");
    invalidate_vector(100, Z);
    matrix_vector_multiply(3, 4, M4, V2, Z);
    print_column_vector(5, Z);
    printf("\n");
        
    
    
    printf("Printing input matrices/vectors (which should be unchanged):\n");
    printf("Input matrix M1:\n");
    print_matrix(4, 3, M1);
    printf("Input matrix M2:\n");
    print_matrix(5, 3, M2);
    printf("Input matrix M3:\n");
    print_matrix(3, 4, M3);
    printf("Input matrix M4:\n");
    print_matrix(3, 4, M4);
    printf("\n");
    printf("Input Vector V1:\n");
    print_column_vector(3, V1);
    printf("Input Vector V2:\n");
    print_column_vector(4, V2);
    printf("\n");
    
    
    
    return 0;
}