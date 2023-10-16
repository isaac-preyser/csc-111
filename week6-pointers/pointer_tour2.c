/* pointer_tour2.c

   Task: Take a scenic tour of pointer types and operations in C.

   Challenge Task: Do the above without panicking.

   B. Bird - 2020-10-14
*/

#include <stdio.h>

int main() {

    int x = 6;
    int y = 10;
    int* p = &x;
    printf("Start: x = %d, y = %d, *p = %d\n", x, y, *p);
    
    /* Task 3: Set y to equal the value of x plus 1000, but do 
               not use the name "x" in the assignment statement. */

    y = *p + 1000;

    printf("Task 3: x = %d, y = %d, *p = %d\n", x, y, *p);


    /* Task 4: Use p to set x to -50, then reset p to point at y. */

    *p = -50;
    p = &y; 

    printf("Task 4: x = %d, y = %d, *p = %d\n", x, y, *p);

    /* Task 5: With p still pointing at y, create a new pointer q which
               points at x. */
    
    int* q;
    q = &x;

    printf("Task 5: x = %d, y = %d, *p = %d, *q = %d\n", x, y, *p, *q);
    

    /* Task 6: Using only the variables p and q, 
       copy the value of x into y. */

    *p = *q;
    
    printf("Task 6: x = %d, y = %d, *p = %d, *q = %d\n", x, y, *p, *q);

    return 0;
}