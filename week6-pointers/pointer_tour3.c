/* pointer_tour3.c

   Task: Take a scenic tour of pointer types and operations in C.

   Challenge Task: Do the above without panicking.

   B. Bird - 2020-10-14
*/

#include <stdio.h>

int main() {


    int x = 6;
    int y = 10;
    int* p = &x;
    int* q = &y;

    printf("Start: x = %d, y = %d, *p = %d, *q = %d\n", x, y, *p, *q);
        
    /* Task 7: Using only the variables p and q, modify p to point at y. */

    p = q;

    printf("Task 7: x = %d, y = %d, *p = %d, *q = %d\n", x, y, *p, *q);

    /* Task 8: Create a pointer Z which points at q. */

    int** Z = &q;

    printf("Task 8: x = %d, y = %d, *p = %d, *q = %d, **Z = %d\n", x, y, *p, *q, **Z);

    /* Task 9: Assign 1000 to the variable y without using the name "y". */

    **Z = 1000;
    
    printf("Task 9: x = %d, y = %d, *p = %d, *q = %d, **Z = %d\n", x, y, *p, *q, **Z);

    /* Task 10: Without using the name "q", make the variable q point at x. */
    
    *Z = &x;
    
    printf("Task 10: x = %d, y = %d, *p = %d, *q = %d, **Z = %d\n", x, y, *p, *q, **Z);

    /* Task 11: Without using the names "x" or "q", make the variable p point at x. */

    p = *Z;

    printf("Task 11: x = %d, y = %d, *p = %d, *q = %d, **Z = %d\n", x, y, *p, *q, **Z);

    return 0;
}