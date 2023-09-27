#include <stdio.h>
#include <stdlib.h>

void print_arithmetic( double a, double b, int n ){

    int i;
    for(i = 0; i < n; i++){
	double sequence_term = a + i*b;
	printf("%.2f ", sequence_term); //The "%.2f" specifier prints values with 2 decimal places.
    }
    printf("\n");
}

double read_double(){
    double val;
    int values_read;
    values_read = scanf("%lf",&val);

    //Test if anything was read (scanf will return the total number of values read)
    if (values_read != 1){
	//If it was not possible to read a value, print an error message and exit the program.
	//(The exit() function is used to immediately exit a C program)
	printf("Error: Invalid value entered. Program will exit.\n");
	exit(0);
    }
    return val;
}

int main(){
    double a = read_double(); 
    double b = read_double();
    printf("Printing ten terms of the arithmetic sequence with a = %.2f, b = %.2f\n", a, b);
    print_arithmetic( a, b, 10); 
    
}

