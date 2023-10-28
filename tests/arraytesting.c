#include <stdio.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    printf("the size of the array is: %li", sizeof(a)/sizeof(a[0]));
    return 0;



}