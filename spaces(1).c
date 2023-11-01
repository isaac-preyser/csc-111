#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* condense_spaces(str, output)
   Given a string str, copy the contents into 
   the string output, deleting any runs of consecutive
   spaces. For example, multiple spaces between words
   should be condensed into a single space.
   Multiple spaces at the beginning and end of the string
   should also be condensed into a single space.
   Use the isspace() function to detect whether a character
   is a space.
*/
void condense_spaces(char str[], char output[]){
    /* Your Code Here */
    int i = 0;
    
  
    while (i <= strlen(str)){
        if (!isspace(str[i])){
            //if the character IS NOT a space, put it in the output
            output[i] = str[i];
        } else if (isspace(str[i]) && !isspace(str[i+1])){
            //if the current character is a space, but the next character is not, put it in the output
            printf("insert space, %d\n", i);
            output[i] = str[i];
        } else {
            printf("index %d skipped\n", i);
        }
        //if neither conditions are true, continue. (i.e. character is a space, and the following character is a space) 
        i++;   
    }
    output[i+1] = '\0';
    
    
}

/* remove_leading_spaces(str, output)
   Given a string str, copy the contents into 
   the string output, ignoring any leading
   spaces (spaces at the beginning of the string).
*/
void remove_leading_spaces(char str[], char output[]){
    /* Your Code Here */
}

/* remove_trailing_spaces(str, output)
   Given a string str, copy the contents into 
   the string output, ignoring any trailing
   spaces (spaces at the end of the string).
*/
void remove_trailing_spaces(char str[], char output[]){
    /* Your Code Here */
}
int main(){

    char S1[] = "Hello         World ";
    char S2[] = "      "; //Contains 0 words, 6 characters
    char S3[] = "CSC    111    Fall 2023";
    char S4[] = "   raspberry    pear pineapple    banana  ";
    char S5[] = "   <-- spaces at the beginning, spaces at the end --> ";

    //Make a new array (initialized to an empty string) to use for the output.
    char W[1000] = "";

    printf("S1: \"%s\", size: %li\n", S1, strlen(S1));
    condense_spaces(S1, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S1, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S1, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    printf("S2: \"%s\"\n", S2);
    condense_spaces(S2, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S2, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S2, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    printf("S3: \"%s\"\n", S3);
    condense_spaces(S3, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S3, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S3, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    printf("S4: \"%s\"\n", S4);
    condense_spaces(S4, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S4, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S4, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    printf("S5: \"%s\"\n", S5);
    condense_spaces(S5, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S5, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S5, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    return 0;
}