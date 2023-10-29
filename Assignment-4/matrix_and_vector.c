#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_and_vector.h"

//gcc -Wall -std=c18 -o vector_tester vector_tester.c matrix_and_vector.c -lm

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
    int skipped = 0; //boolean value
    for (int i = 0; i < n; i++){
        //looping over every row
        if (i == omit_idx){
            //if we're on the row we want to omit, set skipped to 1 and continue
            skipped = 1;
            continue;
        }
        if (skipped){
            //if skipped is true, we want to set the value of the output matrix to the value of the input matrix, but shifted down by one
            for (int j = 0; j < k; j++){
                //fill the column, shifted down by one
                B[i-1][j] = A[i][j];
            }
        } else {
            //if we get here, then we haven't skipped a row yet - so we want to set the value of the output matrix to the value of the input matrix
            for (int j = 0; j < k; j++){
                //fill the column as normal. 
                B[i][j] = A[i][j];
            }
        }

    }
}

void omit_column(int n, int k, double A[n][k], double B[n][k-1], int omit_idx){
    int skipped = 0; 
    for (int j = 0; j < k; j++){
        //this is the column loop
        if (j == omit_idx){
            //if we're on the column we want to omit, set skipped to 1 and continue
            skipped = 1;
            continue;
        }
        //if we have skipped, then fill in the output matrix with the value of the input matrix, but shifted over by one
        if (skipped){
            for (int i = 0; i < n; i++){
                B[i][j-1] = A[i][j];
            }
        } else {
            //if we haven't skipped, then fill in the output matrix with the value of the input matrix
            for (int i = 0; i < n; i++){
                B[i][j] = A[i][j];
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
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
           A[i][j] = V[j];
        }
        
        //shift all the values in V to the left by 1, and moving the first value to the end
        double temp = V[0];
        for (int i = 0; i < n-1; i++){
            V[i] = V[i+1];
        }
        V[n-1] = temp;

        
        
        
        // //shift all the values in V to the right by 1, and moving the last value to the beginning
        // double temp = V[n-1];
        // for (int i = n-1; i > 0; i--){
        //     V[i] = V[i-1];
        // }
        // V[0] = temp;
    }
    return;



}

void matrix_vector_multiply(int n, int k, double A[n][k], double V[k], double Vout[n]){
    for (int i = 0; i < k; i++){
        Vout[i] = 0; //make sure Vout is all zeros
    }
    
    //take the dot product of each row of A with V and store the result in Vout
    for (int i = 0; i < n; i++){
        double sum = 0;
        for (int j = 0; j < k; j++){
            sum += A[i][j] * V[j];
        }
        Vout[i] = sum;
    }

    

    //something in the math isnt mathing

    
    return;
}

void matrix_multiply(int m, int n, int k, double A[m][n], double B[n][k], double C[m][k]){
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < k; j++){
            C[i][j] = 0; //set everything in C to zero, just in case we get a matrix that isn't already zero.
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < k; j++){
           //do the dot product of the ith row of A and the jth column of B
              for (int l = 0; l < n; l++){
                C[i][j] += A[i][l] * B[l][j];
              }
        }
    }


    
    return;
}

void set_vector(int n, double V[n], double s){
    for (int i = 0; i < n; i++){
        V[i] = s; //set all values in the vector to the value of s
    }
    
    return;
}

void mul_vector_by_scalar(int n, double Vin[n], double Vout[n], double s){
    for (int i = 0; i < n; i++){
        Vout[i] = Vin[i] * s; //multiply the vector by the scalar and store the result in the output vector
    }
    return;
}