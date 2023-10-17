#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_and_vector.h"

int matrices_invalid(double V1[n], double V2[n]){
     if (sizeof(V1) != sizeof(V2)){ //if the two vectors are not the same size, return 0
        printf("The two vectors are not the same size\n");
        return 1;
    }
    else{
        return 0;
    }
}

//implment dot product function

double dot_product(int n, double V1[n], double V2[n]){
    if (matrices_invalid(V1, V2) == 1){ //if the two vectors are not the same size, return 0
        return 0;
    }
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += V1[i] * V2[i]; //V1[i] * V2[i] is the dot product of the two vectors, this repeat until the two vectors are multiplied
    }
    return sum;

}

double norm(int n, double V[n]){
    //return the length of the vector, which the square root of the of the dot product of the vector with itself
    return sqrt(dot_product(n, V, V));
}

double angle_between_vectors(int n, double V1[n], double V2[n]) {
    if (matrices_invalid(V1, V2) == 1){ //if the two vectors are not the same size, return 0
        return 0;
    }
    //return the angle between two vectors, which is the inverse cosine of the quotient of the dot product of the two vectors divided by the product of the length of the two vectors
    return acos(dot_product(n, V1, V2) / (norm(n, V1) * norm(n, V2)));
}

void add_vectors(int n, double V1[n], double V2[n], double Vout[n]){
    if (matrices_invalid(V1, V2) == 1){ //if the two vectors are not the same size, return 0
        return;
    }
    double *p_out[n] = &Vout[n]; //create a pointer to the output vector

    for(int i = 0; i < n; i++){
        *p_out[i] = V1[i] + V2[i]; //add the two vectors together and store the result in the output vector
    }
    return;
}

//BEGIN MATRIX FUNCTIONS

void identity(int n, double M[n][n]){
    if (n < 1){ //if the matrix is not square, return
        printf("The matrix is not square\n");
        return;
    }
    
    double *p_M[n][n] = &M[n][n]; //create a pointer to the matrix
    *p_M[n][n] = {0}; //set all values in the matrix to 0
    for(int i = 0; i < n; i++){
        *p_M[i][i] = 1; //set the diagonal values to 1
    }
    return;
}

int matrices_equal(int rows, int cols, double A[rows][cols], double B[rows][cols]){
    if(sizeof(A) != sizeof(B)){ //if the two matrices are not the same size, return 0
        printf("The two matrices are not the same size\n");
        return 0;
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(A[i][j] != B[i][j]){ //if any of the values in the two matrices are not equal, return 0
                return 0;
            }
        }
    }
    return 1; //if we make it through all of this, it's equal. return 1. 
}

void add_matrices(int rows, int cols, double A[rows][cols], double B[rows][cols], double C[rows][cols]){
    if (matrices_equal(rows, cols, A, B) == 0){ //if the two matrices are not the same size, return
        return;
    }
    double *p_C[rows][cols] = &C[rows][cols]; //create a pointer to the output matrix
    *p_C[rows][cols] = {0}; //set all values in the matrix to 0
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            *p_C[i][j] = A[i][j] + B[i][j]; //add the two matrices together and store the result in the output matrix
        }
    }
    return;
}

double trace(int n, double A[n][n]){
    if (matrices_invalid(A, A) == 1){ //if the two matrices are not the same size, return 0
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += A[i][i]; //add the diagonal values of the matrix together
    }
    return sum;
}

void transpose(int n, int k, double A[n][k], double T[k][n]) {
    //essentially, rows become columns. 
    double *p_T[k][n] = &T[k][n]; //create a pointer to the output matrix

    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            *p_T[j][i] = A[i][j]; //set the value of the output matrix to the value of the input matrix, but with the rows and columns switched
        }
    }
}

void omit_row(int n, int k, double A[n][k], double B[n-1][k], int omit_idx){
    
}
