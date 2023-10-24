/* vector_tester.c
   CSC 111 - Fall 2023 - Assignment 4

   Some basic tests for the vector functions. You should modify the test cases 
   and/or add your own tests to ensure that your functions are validated
   thoroughly.

   B. Bird - 2023-10-14
*/


#include <stdio.h>
#include <math.h>
#include "matrix_and_vector.h"

void print_vector(int size, double V[size]){
    for (int i = 0; i < size; i++)
        printf("%.2f ", V[i]);
    printf("\n");
}

int main(){

    double V[] = {1, 2, 3, 4, 5};
    double W[] = {0, 1, 0, 1, 0};
    double X[] = {10, 20, 30, 3.5, 3.6, 3.1415, 1.7};
    double Y[] = {111, 116, 225, 230, 265, 445};
    double Z[] = {0, 0, 0, 999, 999};

    double Q[100]; //Deliberately too large to allow this vector to be used as the output for multiple test cases

    printf("Testing set_vector:\n");
    set_vector(3, Z, 6);
    printf("Result (1): ");
    print_vector(5, Z);
    set_vector(5, Z, 1.87);
    printf("Result (2): ");
    print_vector(5, Z);
    printf("\n");



    printf("Testing mul_vector_by_scalar:\n");
    //Set the first 100 elements of Q to -999
    set_vector(100, Q, -999);
    mul_vector_by_scalar(5, V, Q, 1.5);
    printf("Result (1): ");
    print_vector(5, Q);

    //Now call mul_vector_by_scalar but deliberately decrease
    //the provided size (so the last two elements should remain
    //as -999).
    set_vector(100, Q, -999);
    mul_vector_by_scalar(3, V, Q, 1.5);
    printf("Result (2): ");
    print_vector(5, Q);
    printf("\n");



    printf("Testing dot_product:\n");
    printf("Result (V dot W, size 3): %.2f\n", dot_product(3, V, W));
    printf("Result (V dot W, size 5): %.2f\n", dot_product(5, V, W));
    printf("Result (W dot X, size 5): %.2f\n", dot_product(5, W, X));
    printf("\n");


    printf("Testing norm:\n");
    printf("Result (norm of V, 3 elements): %.2f\n", norm(3, V));
    printf("Result (norm of W, 5 elements): %.2f\n", norm(5, W));
    printf("Result (norm of X, 7 elements): %.2f\n", norm(7, X));
    printf("\n");


    printf("Testing angle_between_vectors:\n");
    printf("Result (V and W, 2 elements): %.2f\n", angle_between_vectors(2, V, W));
    printf("Result (V and W, 3 elements): %.2f\n", angle_between_vectors(3, V, W));
    printf("Result (V and X, 3 elements): %.2f\n", angle_between_vectors(3, V, X));
    printf("\n");



    printf("Testing add_vectors:\n");
    set_vector(100, Q, -999);
    add_vectors(3, V, W, Q);
    printf("Result (V + W, 3 elements): ");
    print_vector(5,Q);

    set_vector(100, Q, -999);
    add_vectors(5, V, W, Q);
    printf("Result (V + W, 5 elements): ");
    print_vector(5, Q);

    set_vector(100, Q, -999);
    add_vectors(6, X, Y, Q);
    printf("Result (X + Y, 6 elements): ");
    print_vector(6, Q);
    printf("\n");


    printf("Testing matrix_vector_multiply:\n");
    double M1[2][2] = {{1,2},{3,4}};
    double M2[2][2] = {{1,0},{0,1}};
    matrix_multiply(2, 2, 2, M1, M2, Q);
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++)
            printf("%.2f ", Q[i][j]);
    }
    printf("\n");
    return 0;
}
