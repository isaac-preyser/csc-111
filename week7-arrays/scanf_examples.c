/* scanf_examples.c

   B. Bird - 2023-10-14
*/



#include <stdio.h>

int main() {
    //Task: Read three integers from the user and print
    //      them out in reverse order. If fewer than
    //      three numbers are entered (or the user enters
    //      non-numerical data), print an error message.

    int v1 = 1000, v2 = 2000, v3 = 3000; //Placeholders
    printf("Enter three numbers: ");

    /* Read them all together */
    if(scanf("%d %d %d", &v1, &v2, &v3) != 3){
        printf("Error: Could not read three numbers\n");
        return 1;
    }

    /* Read them one at a time */
    // scanf("%d", &v1);
    // scanf("%d", &v2);
    // scanf("%d", &v3);

    printf("Values: %d %d %d\n", v3, v2, v1);

    /*
    printf("Which value do you want (1, 2 or 3)? ");
    */
    return 0;
}
