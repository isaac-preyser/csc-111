#include <stdio.h>

/* Put your compute_power function here */
int compute_power(int base, int exponent){
    int out = base;  
    
    for(int i = 1; i < exponent; i++){
     out = out*base;
    }
    return out;
    
    
}



int main(){

    int p1 = compute_power(2, 10);
    int p2 = compute_power(3, 2);
    int p3 = compute_power(9, 3);
    int p4 = compute_power(6, 10);

    printf("2 to the power of 10 is %d\n", p1);
    printf("3 to the power of 2 is %d\n", p2);
    printf("9 to the power of 3 is %d\n", p3);
    printf("6 to the power of 10 is %d\n", p4);

    return 0;
}