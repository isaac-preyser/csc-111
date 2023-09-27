#include <stdio.h> 
void print_arithmetic( double a, double b, int n ){

    int i;
    for(i = 0; i < n; i++){
	double sequence_term = a + i*b;
	printf("%.2f ", sequence_term); //The "%.2f" specifier prints values with 2 decimal places.
    }
    printf("\n");
}

int main(){
    double a, b; 
    int n;
    a = 6.0; b = 10.0; n = 17; 
    printf("Sequence with a = %.2f, b = %.2f, n = %d: ", a, b, n);
    print_arithmetic( a, b, n);
    a = 1.0; b = 111.0; n = 5; 
    printf("Sequence with a = %.2f, b = %.2f, n = %d: ", a, b, n);
    print_arithmetic( a, b, n);
    a = 0.0; b = 1.16; n = 3; 
    printf("Sequence with a = %.2f, b = %.2f, n = %d: ", a, b, n);
    print_arithmetic( a, b, n);

    
    
}