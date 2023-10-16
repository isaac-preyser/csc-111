/* matrix_tester.c
   CSC 111 - Fall 2023 - Assignment 4

   Some basic tests for the matrix functions. You should modify the test cases 
   and/or add your own tests to ensure that your functions are validated
   thoroughly.

   B. Bird - 2023-10-14
*/

    
//Warning: The tests below only validate the "actual" entries of each matrix.
//         If your code accidentally sets invalid elements (e.g. elements outside
//         the bounds of the array), these tests might not expose the problem,
//         but you could still lose marks.

#include <stdio.h>
#include <math.h>
#include "matrix_and_vector.h"


void print_matrix(int rows, int columns, double M[rows][columns]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++)
            printf("%7.2f ", M[i][j]);
        printf("\n");
    }
}
    
//print_column_vector(V, size)
//Print the contents of the vector V as a column (analogous to a 1 x size matrix)
void print_column_vector(int size, double V[size]){
    for (int i = 0; i < size; i++)
        printf("%7.2f\n", V[i]);
}

int main(){

    double M1[3][3] = { {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9} };

    double M2[3][3] = { {1, 1, 1},
                        {0, 2, 2},
                        {0, 0, 3}	};

    double M3[2][5] = { {6, 10, 17, 187, 225},
                        {0.5, 0.25, 0.5, 0.25, 0.5} };

    double M4[5][2] = { {1, 0},
                        {0, 1},
                        {1, 1},
                        {-1, 1},
                        {0, 0} };
    
    double M5[4][3] = { {1, 0.5, 0.33},
                        {0.5, 0.33, 0.25},
                        {0.33, 0.25, 0.2},
                        {0.25, 0.2, 0.16} };

    double M6[4][4] = { {1, 0.5, 0.33, 0.25},
                        {0.5, 0.33, 0.25, 0.2},
                        {0.33, 0.25, 0.2, 0.16},
                        {0.25, 0.2, 0.16, 0.14} };
    
    double M7[4][3] = { {1, 1, 1},
                        {1, 2, 2},
                        {1, 2, 3},
                        {1, 2, 3} };
    
    //M8 is deliberately identical to M7
    double M8[4][3] = { {1, 1, 1},
                        {1, 2, 2},
                        {1, 2, 3},
                        {1, 2, 3} };

    double V1[] = {-0.5, 0.5};
    double V2[] = {9, -9, 1};
    double V3[] = {1, 2, 3, 4};
    double V4[] = {10, 20, 30};
    double V5[] = {6, 10, 17, 187};
    

    double I3[3][3], I5[5][5];
    printf("Testing identity:\n");
    printf("3 x 3 identity matrix:\n");
    identity(3, I3);
    print_matrix(3, 3, I3);
    printf("\n");
    printf("5 x 5 identity matrix:\n");
    identity(5, I5);
    print_matrix(5, 5, I5);
    printf("\n");
    printf("\n");


    printf("Testing matrices_equal:\n");
    printf("Is M1 equal to itself? matrices_equal returns %d\n", matrices_equal(3,3,M1,M1));
    printf("Are M1 and M2 equal? matrices_equal returns %d\n", matrices_equal(3,3,M1,M2));
    printf("Are M7 and M8 equal? matrices_equal returns %d\n", matrices_equal(4,3,M7,M8));
    printf("Are M5 and M7 equal? matrices_equal returns %d\n", matrices_equal(4,3,M5,M7));
    printf("\n");
    printf("\n");

    
    double T1[3][3], T2[5][2];
    printf("Testing transpose:\n");
    printf("Transpose of M1:\n");
    transpose(3, 3, M1, T1);
    print_matrix(3, 3, T1);
    printf("\n");
    printf("Transpose of M3:\n");
    transpose(2, 5, M3, T2);
    print_matrix(5, 2, T2); //Note that that the row/column counts are swapped by transposing
    printf("\n");
    printf("\n");
    
    
    double OmitRow1[3][4], OmitRow2[4][2];
    printf("Testing omit_row:\n");
    printf("Omitting row 0 from M6:\n");
    omit_row(4, 4, M6, OmitRow1, 0);
    print_matrix(3, 4, OmitRow1);
    printf("\n");
    printf("Omitting row 2 from M6:\n");
    omit_row(4, 4, M6, OmitRow1, 2);
    print_matrix(3, 4, OmitRow1);
    printf("\n");
    printf("Omitting row 3 from M4:\n");
    omit_row(5, 2, M4, OmitRow2, 3);
    print_matrix(4, 2, OmitRow2);
    printf("\n");
    
    
    double OmitCol1[4][3], OmitCol2[2][4];
    printf("Testing omit_column:\n");
    printf("Omitting column 0 from M6:\n");
    omit_column(4, 4, M6, OmitCol1, 0);
    print_matrix(4, 3, OmitCol1);
    printf("\n");
    printf("Omitting column 3 from M6:\n");
    omit_column(4, 4, M6, OmitCol1, 3);
    print_matrix(4, 3, OmitCol1);
    printf("\n");
    printf("Omitting column 3 from M3:\n");
    omit_column(2, 5, M3, OmitCol2, 3);
    print_matrix(2, 4, OmitCol2);
    printf("\n");
    

    double Add1[3][3], Add2[4][3];
    printf("Testing add_matrices:\n");
    printf("M1 + M2:\n");
    add_matrices(3, 3, M1, M2, Add1);
    print_matrix(3, 3, Add1);
    printf("\n");
    printf("M5 + M7:\n");
    add_matrices(4, 3, M5, M7, Add2);
    print_matrix(4, 3, Add2);
    printf("\n");
    printf("\n");


    printf("Testing trace:\n");
    printf("Trace of M1: %.2f\n", trace(3, M1));
    printf("Trace of M2: %.2f\n", trace(3, M2));
    printf("Trace of M6: %.2f\n", trace(4, M6));
    printf("\n");
    printf("\n");


    double Outer1[2][2], Outer2[3][3], Outer3[3][4], Outer4[4][2];
    printf("Testing outer_product:\n");
    printf("V1 (x) V1:\n");
    outer_product(2, 2, V1, V1, Outer1);
    print_matrix(2, 2, Outer1);
    printf("\n");
    printf("V2 (x) V4:\n");
    outer_product(3, 3, V2, V4, Outer2);
    print_matrix(3, 3, Outer2);
    printf("\n");
    printf("V4 (x) V5:\n");
    outer_product(3, 4, V4, V5, Outer3);
    print_matrix(3, 4, Outer3);
    printf("\n");
    printf("V5 (x) V1:\n");
    outer_product(4, 2, V5, V1, Outer4);
    print_matrix(4, 2, Outer4);
    printf("\n");
    printf("\n");


    double Circ1[3][3], Circ2[4][4];
    printf("Testing circulant:\n");
    printf("Circulant matrix specified by V2:\n");
    circulant(3,Circ1,V2);
    print_matrix(3,3,Circ1);
    printf("\n");
    printf("Circulant matrix specified by V3:\n");
    circulant(4,Circ2,V3);
    print_matrix(4,4,Circ2);
    printf("\n");
    printf("\n");


    double Vout[100]; //This is deliberately too large so that we can use it as the output for multiple tests.
    printf("Testing matrix_vector_multiply:\n");
    printf("(The results of each part are printed as column vectors)\n");
    printf("M1 * V2:\n");
    matrix_vector_multiply(3, 3, M1, V2, Vout);
    print_column_vector(3, Vout);
    printf("\n");
    printf("M2 * V2:\n");
    matrix_vector_multiply(3, 3, M2, V2, Vout);
    print_column_vector(3, Vout);
    printf("\n");
    printf("M4 * V1:\n");
    matrix_vector_multiply(5, 2, M4, V1, Vout);
    print_column_vector(5, Vout);
    printf("\n");
    printf("M5 * V2:\n");
    matrix_vector_multiply(4, 3, M5, V2, Vout);
    print_column_vector(4, Vout);
    printf("\n");
    printf("M6 * V3:\n");
    matrix_vector_multiply(4, 4, M6, V3, Vout);
    print_column_vector(4, Vout);
    printf("\n");
    printf("M7 * V2:\n");
    matrix_vector_multiply(4, 3, M7, V2, Vout);
    print_column_vector(4, Vout);
    printf("\n");
    printf("\n");


    double Mul1[3][3], Mul2[2][2], Mul3[5][5], Mul4[4][4], Mul5[4][3];
    printf("Testing matrix_multiply:\n");
    printf("M1 * M2:\n");
    matrix_multiply(3, 3, 3, M1, M2, Mul1);
    print_matrix(3, 3, Mul1);
    printf("\n");
    printf("M3 * M4:\n");
    matrix_multiply(2, 5, 2, M3, M4, Mul2);
    print_matrix(2, 2, Mul2);
    printf("\n");
    printf("M4 * M3:\n");
    matrix_multiply(5, 2, 5, M4, M3, Mul3);
    print_matrix(5, 5, Mul3);
    printf("\n");
    printf("M6 * M6:\n");
    matrix_multiply(4, 4, 4, M6, M6, Mul4);
    print_matrix(4, 4, Mul4);
    printf("\n");
    printf("M6 * M5:\n");
    matrix_multiply(4, 4, 3, M6, M5, Mul5);
    print_matrix(4, 3, Mul5);
    printf("\n");
    printf("M6 * M7:\n");
    matrix_multiply(4, 4, 3, M6, M7, Mul5);
    print_matrix(4, 3, Mul5);
    printf("\n");
    printf("\n");


    return 0;
}
