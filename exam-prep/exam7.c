#include <stdio.h>

/* last_word(input_string, output_array)
Given a null terminated C string input_string and an output output_array,
set output_array to contain a null-terminated C string containing the last
word in input_string. You may assume that the input string contains only
letters (uppercase/lowercase) and spaces. No newlines, tabs, punctuation
or other characters will appear. The last word is defined to be the last
sequence of one or more contiguous non-space characters in the string.
See the examples below for various special cases.

 Note that the output string should be empty if the input string is empty
 or if the input string contains no word characters.
 Don't forget the null terminator.

 You may assume that output_array will always have enough space to store the
 desired output (so no bounds checking is needed).
 */
 /* (your code would be placed here) */

void last_word (char input_string[], char output_array[]){
 //write a function that accepts and input string and an output array, and sets the output array to contain the last word in the input string
    //you may assume that the input string contains only letters (uppercase/lowercase) and spaces. No newlines, tabs, punctuation or other characters will appear
    //the last word is defined to be the last sequence of one or more contiguous non-space characters in the string
    //see the examples below for various special cases
    //note that the output string should be empty if the input string is empty or if the input string contains no word characters
    //don't forget the null terminator
    //you may assume that output_array will always have enough space to store the desired output (so no bounds checking is needed)
    
    //get the length of the input string
    int length = 0;
    while(input_string[length] != '\0'){
        length++;
    }
    
    //find the last word
    int lastWordStart = -1;
    int lastWordEnd = -1;
    for(int i = length - 1; i >= 0; i--){
        if(input_string[i] != ' '){
            lastWordEnd = i;
            break;
        } //if we get back to the beginning of the string, and we have found a non-space character, then the last word is the whole string
    }
    for(int i = lastWordEnd; i >= 0; i--){
        if(input_string[i] == ' '){
            lastWordStart = i + 1;
            break;
        }   else if(i == 0){
            lastWordStart = 0;
            lastWordEnd = length - 1;
            break;
        }
    }
    
    
    //copy the last word into the output array
    for(int i = lastWordStart; i <= lastWordEnd; i++){
        output_array[i - lastWordStart] = input_string[i];
    }
    output_array[lastWordEnd - lastWordStart + 1] = '\0';
    
    return;
}


 int main(){
 char S1[] = "Hello World";
 char S2[] = " Raspberry";
 char S3[] = "Programming";
 char S4[] = " This string starts and ends with spaces ";

 char output[100];
 last_word(S1, output);
 printf("Result for S1: \"%s\"\n", output );
 last_word(S2, output);
 printf("Result for S2: \"%s\"\n", output );
 last_word(S3, output);
 printf("Result for S3: \"%s\"\n", output );
 last_word(S4, output);
 printf("Result for S4: \"%s\"\n", output );
 return 0;
 }
 