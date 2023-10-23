/* creating_arrays.c
   
   B. Bird - 2023-10-22
*/

#include <stdio.h>



int main() {
    int i;

    //Creating an array with the notation below does NOT initialize
    //any elements. Therefore, all elements of U will have uninitialized
    //(garbage) values until they are explicitly set.
    
    //Task: Create an uninitialized array U with 20 elements

    printf("Contents of U: ");
    for(i = 0; i < 20; i++){
        printf("%d ", U[i]);
    }
    printf("\n");

    //An array can also be created with an initializer to give each element
    //an initial value. The initializer consists of a list of elements
    //enclosed in curly brackets.

    //Task: Create an array A of size 5 initialized to contain the elements
    //      3, 14, 15, 9, 2

    /*
    printf("Contents of A: ");
    for(i = 0; i < 5; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    */

    //The array B below has an initializer with fewer elements than its 
    //specified size. In such a case, the compiler initializes the first
    //few elements to be those specified by the initializer and sets the
    //remaining elements to zero.
    

    //Task: Create an array B with 5 elements, where the first
    //      two elements are initialized to the values 6, 10 and
    //      the remaining elements are automatically set to zero.

    /*
    printf("Contents of B: ");
    for(i = 0; i < 5; i++){
        printf("%d ", B[i]);
    }
    printf("\n");
    */

    //An incomplete initializer is a convenient way to initialize an entire
    //array to zero. For example, instead of writing a loop to set all
    //1000000 elements to zero, we can create a zero-initialized array
    //with the following syntax.
    //(Note that the compiler likely generates a loop for us in this case,
    // so there's no actual performance difference).
    int Z[1000000] = {0};


    //Question: Given an array that has already been created, is there a way
    //          to determine its size programmatically?
    return 0;
}
