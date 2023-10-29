#include <stdio.h>


void omit_column(int n, int k, double A[n][k], double B[n][k-1], int omit_idx){
    int skipped = 0; 
    for (int i = 0; i < n; i++){
        //this is the row loop
        for (int j = 0; j < k; j++){
            //this is the column loop
            if (j == omit_idx){
                //if we're on the column we want to omit, set skipped to 1 and continue
                skipped = 1;
                continue;
            }
            //if we have skipped, then fill in the output matrix with the value of the input matrix, but shifted over by one
            if (skipped){
                B[i][j-1] = A[i][j];
            } else {
                //if we haven't skipped, then fill in the output matrix with the value of the input matrix
                B[i][j] = A[i][j];
            }
        }
    }
}


int main() {


}