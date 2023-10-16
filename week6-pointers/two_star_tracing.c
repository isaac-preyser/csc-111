/* two_star_tracing.c

   Task: Determine the output of the code below.

   B. Bird - 2020-10-16
*/

#include <stdio.h>
#include <stdlib.h>

int F(int** A, int** B){
    int z = **A;
    *A = *B;
    **A = 100;
    return z;
}

int main() {
    int x = 6;
    int y = 10;
    int* p = &x;
    int* q = &y;
    int** r = &q;

    int a = 0;
    printf("a = %d, x = %d, y = %d\n",a,x,y);

    a = F(&p, r);

    printf("a = %d, x = %d, y = %d\n",a,x,y);
    *p = 1000;
    printf("a = %d, x = %d, y = %d\n",a,x,y);

    return 0;
}
