/* 2d_array.c
  
   B. Bird - 2023-10-22
*/

#include <stdio.h>

int main() {

    //The array Q below is 2-dimensional
    //We can choose to visualize Q as a table
    //with 3 rows and 2 columns (and in CSC 111,
    //we always assume that "rows" are the first
    //dimension and "columns" are the second one,
    //but this is a convention, not a general
    //rule elsewhere).
    int Q[3][2];

    //Each dimension of Q is indexed separately.
    Q[0][0] = 5; //Row 0, Column 0
    Q[0][1] = 2; //Row 0, Column 1
    Q[1][0] = 6; //Row 1, Column 0
    Q[1][1] = 10; //Row 1, Column 1
    Q[2][0] = -1; //Row 2, Column 0
    Q[2][1] = 187; //Row 2, Column 1

    //Task: Print the elements of Q as a table
    //      (with one row per line).

    return 0;
}

