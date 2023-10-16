/* matrix_and_vector.h
   CSC 111 - Fall 2023 - Assignment 4

   Header file for matrix/vector library.
   Do not put your implementations in this file (create a separate
   matrix_and_vector.c file for that).

   B. Bird - 2023-10-14
*/

#include <math.h> //For the sqrt() function


/****************************** VECTOR FUNCTIONS ******************************/

/* set_vector(n, V, s)
   Given an integer n, a vector V with n elements, and a scalar s,
   copy the value of s into every element of the vector V.
   When this function completes, every element of V will equal
   the value of s.

   Parameters: n (integer), V (array of double), s (double)
   Return value: None
*/
void set_vector(int n, double V[n], double s);

/* mul_vector_by_scalar(n, Vin, Vout, s)
   Given an integer n, an input vector Vin (with size n), an output vector
   Vout (with size n) and a scalar value s, set the vector Vout to contain
   the result of multiplying the vector Vin by the scalar s.

   Do not modify any elements of the input vector Vin.

   Parameters: n (integer), Vin (array of double), Vout (array of double), s (double)
   Return value: None
*/
void mul_vector_by_scalar(int n, double Vin[n], double Vout[n], double s);

/* dot_product(n, V1, V2)
   Given an integer n and two n-element vectors V1 and V2, compute and return
   the dot product of V1 and V2. See Section 2.1 of the specification PDF for
   more information.

   Do not modify any elements of the input vectors V1 and V2.

   Parameters: n (integer), V1 (array of double), V2 (array of double)
   Return value (double): Dot product of V1 and V2
*/
double dot_product(int n, double V1[n], double V2[n]);

/* norm(n, V)
   Given an integer n and a vector V of size n, return the norm (length) of V.

   Recall that the length of a vector V is the square root of the dot product 
   of V with itself. See Section 2.2 of the specification PDF for more 
   information.

   Do not modify any elements of the input vector V.

   Parameters: n (integer), V (array of double)
   Return value (double): Norm (length) of the vector V
*/
double norm(int n, double V[n]);

/* angle_between_vectors(n, V1, V2)
   Given an integer n and two n-element vectors V1 and V2, compute and return
   the angle between the two vectors.

   If either (or both) of the vectors has a length of zero, return -1.

   Otherwise, return the angle between the two vectors. See Section 2.3 of the
   specification PDF for more information.

   Do not modify any elements of the input vector V.

   Parameters: n (integer), V1 (array of double), V2 (array of double)
   Return value (double): 
     - If both V1 and V2 have non-zero length: Return the angle between V1 and V2
     - Otherwise: Return -1
*/
double angle_between_vectors(int n, double V1[n], double V2[n]);


/* add_vectors(n, V1, V2, Vout)
   Given an integer n, two input vectors V1 and V2 (of size n) and an output 
   vector Vout (also of size n), compute the (elementwise) vector sum V1 + V2 
   and store the result into Vout.

   Do not modify any elements of the input vectors V1 and V2.

   Parameters: n (integer), V1 (array of double), V2 (array of double), Vout (array of double)
   Return value: None
*/
void add_vectors(int n, double V1[n], double V2[n], double Vout[n]);




/****************************** MATRIX FUNCTIONS ******************************/


/* identity(size, M)
   Given an integer n and an n x n output matrix M, set M to be the n x n
   identity matrix.

   Parameters: n (integer), M (2d array of double)
   Return value: None
*/
void identity(int n, double M[n][n]);

/* matrices_equal(rows, cols, A, B)
   Given two input matrices A and B (both with the number of rows/columns provided),
   return 1 if they are equal and 0 otherwise.

   (As a simplification, you may assume that two matrices are equal if their elements are
    exactly the same. In practice, matrices would normally be considered equal if elements
    were within some small tolerance value to account for things like rounding errors).

   Parameters: rows (integer), cols (integer), A (2d array of double), B (2d array of double)
   Return value (integer):
     - Return 1 if the two matrices are equal (that is, if each element of A is equal to the corresponding element of B)
     - Return 0 otherwise 
*/
int matrices_equal(int rows, int cols, double A[rows][cols], double B[rows][cols]);

/* add_matrices(rows, cols, A, B, C)
   Given two input matrices A and B (both with the number of rows/columns provided),
   set C to be the elementwise sum of A and B.
   Do not modify any elements of the input matrices A and B.

   Parameters: rows (integer), cols (integer), A (2d array of double), B (2d array of double), C (2d array of double)
   Return value: None
*/
void add_matrices(int rows, int cols, double A[rows][cols], double B[rows][cols], double C[rows][cols]);

/* trace(n, A)
   Given an integer n and a matrix A with n rows and n columns, compute the 
   trace of A.

   The trace of a matrix is the sum of the entries along the forward diagonal.
   For example, consider the matrix
          7 -1 -2 
     A =  6 10 17
          9 20 111
   the trace of A is 7 + 10 + 111 = 128

   Parameters: n (integer), A (2d array of double)
   Return value (double): The trace of A
*/
double trace(int n, double A[n][n]);

/* transpose(n, k, A, T)
   Given integers n and k, along with an n x k input matrix A
   and a k x n output matrix T, set T to be the transpose of A. 

   Do not modify any elements of the input matrix A.

   Parameters: n (integer), k (integer), A (2d array of double), T (2d array of double)
   Return value: None
*/
void transpose(int n, int k, double A[n][k], double T[k][n]);

/* omit_row(n, k, A, B, omit_idx)
   Given integers n and k, along with an n x k input matrix A, an (n-1) x k
   output matrix B and an integer omit_idx, copy the elements of A into B, 
   completely omitting the row with index omit_idx (and shifting the remaining
   rows to fill in the empty space in B created by the omission).
   
   Notice that the dimensions of B has one fewer row than A, since the omitted
   row will not be present in B.

   Do not modify any elements of the input matrix A.

   You may assume that omit_idx is a valid row index. Your code will not be 
   tested on cases where omit_idx is invalid.

   Parameters: n (integer), k (integer), A (2d array of double), 
               B (2d array of double), omit_idx (integer)
   Return value: None
*/
void omit_row(int n, int k, double A[n][k], double B[n-1][k], int omit_idx);

/* omit_column(n, k, A, B, omit_idx)
   Given integers n and k, along with an n x k input matrix A, an n x (k-1)
   output matrix B and an integer omit_idx, copy the elements of A into B, 
   completely omitting the column with index omit_idx (and shifting the 
   remaining columns to fill in the empty space in B created by the omission).
   
   Notice that the dimensions of B has one fewer column than A, since the 
   omitted column will not be present in B.

   Do not modify any elements of the input matrix A.

   You may assume that omit_idx is a valid column index. Your code will not be 
   tested on cases where omit_idx is invalid.

   Parameters: n (integer), k (integer), A (2d array of double), 
               B (2d array of double), omit_idx (integer)
   Return value: None
*/
void omit_column(int n, int k, double A[n][k], double B[n][k-1], int omit_idx);

/* outer_product(n, V1, V2, M)
   Given integers n and m, an n-element vector V1, and an m-element vector V2, 
   along with an n x m output matrix M, set the matrix M to contain the outer 
   product of V1 and V2.

   For more information about outer products, see Section 2.4 of the 
   specification PDF.

   Parameters: n (integer), m (integer), V1 (array of double), 
               V2 (array of double), M (2d array of double)
   Return value: None
*/
void outer_product(int n, int m, double V1[n], double V2[m], double M[n][m]);

/* circulant(n, A, V)
   Given an integer n, a n x n matrix A and an n-element vector V, 
   set A to contain the circulant matrix specified by V.

   The first row of the circulant matrix is a copy of V. Each subsequent 
   row is a copy of the previous row, shifted by one position to the left.

   For example, if V contains (1,2,3,4), the circulant matrix is 
     1 2 3 4
     2 3 4 1
     3 4 1 2
     4 1 2 3

   Parameters: n (integer), A (2d array of double), V (array of double)
   Return value: None
*/
void circulant(int n, double A[n][n], double V[n]);

/* matrix_vector_multiply(n, k, A, V, Vout)
   Given integers n and k, multiply the n x k matrix A by the k-element vector V, 
   producting an n-element vector Vout.

   Note that the product AV where A is an n x k matrix and V is a k-element vector 
   can be computed with the usual matrix multiplication algorithm by treating V 
   as a k x 1 matrix.

   Do not modify any elements of the input matrices A and B or the input vector V.

   Parameters: n (integer), k (integer), A (2d array of double), 
               V (array of double), Vout (array of double)
   Return value: None
*/
void matrix_vector_multiply(int n, int k, double A[n][k], double V[k], double Vout[n]);

/* matrix_multiply(m, n, k, A, B, C)
   Given integers m, n and k, compute the matrix product C = A*B.
   The input matrix A will be m x n and the input matrix B will be n x k.
   The output matrix C will be m x k.
   
   Do not modify any elements of the input matrices A and B.

   If you are unfamiliar with matrix multiplication, a tutorial on basic 
   linear algebra (recorded in Fall 2020) has been posted at
     https://www.youtube.com/watch?v=gxwten_khso
   (for specific details about matrix multiplication, skip to 10:45 in the video)

   You can also take a look at the Wikipedia article
     https://en.wikipedia.org/wiki/Matrix_multiplication

   Parameters: 
      m, n, k (all integers)
      A, B, C (all 2d arrays of double, note the different dimensions in the signature)
   Return value: None
*/
void matrix_multiply(int m, int n, int k, double A[m][n], double B[n][k], double C[m][k]);
