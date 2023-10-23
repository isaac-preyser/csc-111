/* passing_arrays.c

   B. Bird - 2023-10-22
*/

#include <stdio.h>

void a_function(int A[5]){
    A[0] = 0;
    A[1] = 0;
    A[2] = 0;
}


int main() {

    int my_array[5] = {6, 10, 17, 187, 2020};

    for(int i = 0; i < 5; i++){
        printf("%d ", my_array[i]);
    }
    printf("\n");

    a_function(my_array);

    for(int i = 0; i < 5; i++){
        printf("%d ", my_array[i]);
    }
    printf("\n");

    return 0;
}
