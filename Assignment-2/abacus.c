/* abacus.c
   CSC 111 - Fall 2023 - Assignment 2

   I.Preyser - V01022512  2023-09-20
*/

#include <stdio.h>

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
        rename the variables, change their types or move the declarations. */

    long long int abacus_value = 3402845806450;
    long long int largest_group = 100000000000; 

    /* END OF INPUT DATA */
    /* Implement your solution below this line */
    long long int j; //number of beads we are gonna print
    for(long long int g = largest_group; g > 0; g = g / 10){
        j = abacus_value / g; //how many X's can we print per step of the abacus we are on? 
        abacus_value = abacus_value % g; //what we have left over after printing the abacus line
        printf("%lld: ",g);
        while( j > 0 ){
            printf("X");
            j--;
        }
        printf("\n");    
    }
    
    
    

    return 0;
}


