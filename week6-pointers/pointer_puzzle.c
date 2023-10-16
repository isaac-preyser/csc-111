/* pointer_puzzle.c

   B. Bird - 2020-10-16
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 'A';
    int b = 'B';
    int* p = &a;
    int* q = &b;
    int** X = &p;
    int** Y = &q;
    //Task: Using only the variables X and Y, add lines
    //below to achieve the following output:
    //a is 'C', b is 'D'
    //*p is 'D', *q is 'D'


    //
    printf("a is '%c', b is '%c'\n",a,b);
    printf("*p is '%c', *q is '%c'\n",*p, *q);
    return 0;
}
