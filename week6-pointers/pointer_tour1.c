/* pointer_tour1.c

   Task: Take a scenic tour of pointer types and operations in C.

   Challenge Task: Do the above without panicking.

   B. Bird - 2020-10-14
*/

#include <stdio.h>

int main() {
    int x = 6;
    int y = 10;
    printf("Start: x = %d, y = %d\n", x, y);

    /* Task 1: Create a pointer p and set it to point to x */


    int* p;
    p = &x;
    
    printf("Task 1: x = %d, y = %d, *p = %d\n", x, y, *p);
    

    /* Task 2: Use p to modify the value of x to be 100 */
    
    *p = 100;
    
    printf("Task 2: x = %d, y = %d, *p = %d\n", x, y, *p);

    return 0;
}