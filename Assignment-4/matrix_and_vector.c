#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_and_vector.h"



//implment dot product function

double dot_product(int n, double V1[n], double V2[n]){
    
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
    
    //return the angle between two vectors, which is the inverse cosine of the quotient of the dot product of the two vectors divided by the product of the length of the two vectors
    return acos(dot_product(n, V1, V2) / (norm(n, V1) * norm(n, V2)));
}

void add_vectors(int n, double V1[n], double V2[n], double Vout[n]){

    
    for(int i = 0; i < n; i++){
        Vout[i] = V1[i] + V2[i]; //add the two vectors together and store the result in the output vector
    }
    return;
}

//BEGIN MATRIX FUNCTIONS

void identity(int n, double M[n][n]){
    if (n < 1){ //if the matrix is not square, return
        printf("The matrix is not square\n");
        return;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            M[i][j] = 0;
        }

    } //set all values in the matrix to 0
    for(int i = 0; i < n; i++){
        M[i][i] = 1; //set the diagonal values to 1
    }
    return;
}

int matrices_equal(int rows, int cols, double A[rows][cols], double B[rows][cols]){
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
    /*
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            C[i][j] = 0;
        }

    }*/
    //set all values in the matrix to 0
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            C[i][j] = A[i][j] + B[i][j]; //add the two matrices together and store the result in the output matrix
        }
    }
    return;
}

double trace(int n, double A[n][n]){
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += A[i][i]; //add the diagonal values of the matrix together
    }
    return sum;
}

void transpose(int n, int k, double A[n][k], double T[k][n]) {
    //essentially, rows become columns. 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            T[j][i] = A[i][j]; //set the value of the output matrix to the value of the input matrix, but with the rows and columns switched
        }
    }
}

void omit_row(int n, int k, double A[n][k], double B[n-1][k], int omit_idx){
    int skipped = 0;
    for (int i = 0; i < n; i++){
        if (i == omit_idx){
            continue;
            skipped = 1; 
        } else{
            for (int j = 0; j < k; j++){
                if(skipped){
                    B[n-1][k] = A[n][k];
                } else{
                    B[n][k] = A[n][k];
                }
            }
        }
    }
}

void omit_column(int n, int k, double A[n][k], double B[n][k-1], int omit_idx){
    int skipped = 0;
    for (int i = 0; i < k; i++){
        if (i == omit_idx){
            continue;
            skipped = 1; 
        } else{
            for (int j = 0; j < n; j++){
                if(skipped){
                    B[n][k-1] = A[n][k];
                } else{
                    B[n][k] = A[n][k];
                }
            }
        }
    }
}
void outer_product(int n, int m, double V1[n], double V2[m], double M[n][m]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            M[i][j] = V1[i] * V2[j]; //multiply the two vectors together and store the result in the output matrix
        }
    }
    return;
}

void circulant(int n, double A[n][n], double V[n]){
  int shift = 0; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j + shift >= n){
                A[i][j] = V[j + shift - n]; //if the index is greater than the size of the matrix, subtract the size of the matrix from the index
            } else{
                A[i][j] = V[j + shift]; //otherwise, just add the shift to the index
            }
        }
        shift++; //increment the shift
    }
}

void matrix_vector_multiply(int n, int k, double A[n][k], double V[k], double Vout[n]){
    return;
}

void matrix_multiply(int m, int n, int k, double A[m][n], double B[n][k], double C[m][k]){
    return;
}

void set_vector(int n, double V[n], double s){
    return;
}

void mul_vector_by_scalar(int n, double Vin[n], double Vout[n], double s){
    return;
}