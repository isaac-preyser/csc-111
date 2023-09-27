#include <stdio.h>

int main() {
    int num, i, j;
    int rods[10] = {0};

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num > 0) {
        int digit = num % 10;
        rods[digit]++;
        num /= 10;
    }

    for (i = 4; i >= 0; i--) {
        for (j = 0; j < 10; j++) {
            if (rods[j] > i) {
                printf("| o ");
            } else {
                printf("|   ");
            }
        }
        printf("|\n");
    }

    printf("+---+---+---+---+---+---+---+---+---+---+\n");

    return 0;
}
