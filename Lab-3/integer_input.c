#include <stdio.h> 
#include <stdlib.h>

int read_int(){
    int val;
    int values_read;
    values_read = scanf("%d",&val);
    if (values_read != 1){
	printf("Error: Invalid value entered. Program will exit.\n");
	exit(0);
    }
    return val;
}

int main(){
    printf("Enter an integer: ");
    int n = read_int();
    switch(n / abs(n)) {
        case -1:
            printf("The value is negative\n");
            break;
        case 1: 
            if ( n == 0) {
                printf("The value is 0\n");
                break;
            }
            printf("The value is positive\n");
            break;
        default:
            printf("The value is 0\n");
            }
                  
    if(n % 2 == 0){
        printf("The value is even\n");
    }else if(n % 2 != 0){
        printf("The value is odd\n");
    }
    
    
} 