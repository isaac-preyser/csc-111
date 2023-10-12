#include <stdio.h>




int main() {
    char prev[2];
    while(1){ 
        char ch = getchar();
        if (ch == prev[0] && ch == prev[1]){
            printf("Found 3 consecutive %c's\n", ch);
            return 0;
        } else if  (ch == '#'){
            printf("No 3 consecutive characters found\n");
            return 1; 
        }
        prev[0] = prev[1];
        prev[1] = ch;
    }


    return 0;
}
