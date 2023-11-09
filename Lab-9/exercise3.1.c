#include <stdio.h>
#include <ctype.h> 


int main (){
    FILE* input = fopen("text3.txt", "r");
    //print everything as uppercase, and count the amount of characters, and alphabetical characters, printed. 
    int working = fgetc(input); 
    int alpha_count = 0;
    int total = 0; 
    while (working != EOF){
        printf("%c", working); 
        if (isalpha(working)){
            alpha_count++;
        }
        total++;
    }
    printf("\nTotal: %d. Total Alpha: %d.\n", total, alpha_count);
    fclose(input);
    return 0; 
}