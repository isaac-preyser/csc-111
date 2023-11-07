/* vigenere.c
   CSC 111 - Fall 2023 - Assignment 5


   B. Bird - 2023-10-26
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* index_to_character(index)
   Given an index, which MUST be in the range 0 through 25 (inclusive), return
   the corresponding lowercase character of the English alphabet, where
   the index 0 refers to 'a' and the index 25 refers to 'z'.

   If the index is not in the range 0 through 25, the behavior of this function
   is undefined.

   Parameters: index (integer)
   Return value (char): The character of the English alphabet with the
                        provided index.
*/
char index_to_character(int index){
    return 'a' + index;
}


/* character_to_index(ch)
   Given a lowercase English letter, return the index of that character in the
   English alphabet, where 'a' has the index 0 and 'z' has the index 25.

   If the character is not a lowercase letter, the behavior of this function
   is undefined.

   Parameters: ch (character)
   Return value (int): The index of the provided character in the English
                       alphabet.
*/
int character_to_index(char ch){
    return ch - 'a';
}


int main(){

    char key[100];
    char message[100];
    char encrypted[100];
    char decrypted[100];

    //open input.txt for input reading
    FILE* input_file = fopen("input.txt","r");
    if (!input_file){
        printf("Error: Unable to open input file.\n");
        return 1;
    }
    //read the first line of text, and set it to the key. 
    //Note: The key may contain spaces, so use fgets instead of fscanf.
    //however, if spaces are indeed intentional, this code will fail the test case. 
    //I will write my code assuming that the should not contain spaces. 
    fgets(key,100,input_file);
    //The next line will be the message. 
    fgets(message, 100, input_file);
    //if the key has length of 0, throw an invalid key error. 
    if (strlen(key) <= 0){
        printf("Error: Invalid Key."\n);
        //close input.txt
        fclose(input_file);
        return 1; 
    }
    //if the message has a length of 0, OR contains any non-lowercase characters, throw an invalid message error. 
    if (strlen(message) <= 0){
        printf("Error: Invalid message."\n);
        //close input.txt
        fclose(input_file);
        return 1; 
    }
    for (int i = 0; i <= strlen(message); i++){
        //this might walk off the end of the string, I have no idea
        if (islower(message[i]) == 0)
        {
            //if we get in here we throw errors broski
            printf("Error: Invalid message."\n);
            //close input.txt
            fclose(input_file);
            return 1; 
        }
    }
//if we get here, we can rest assured both the message and the key are valid. 
//we print the message
printf(); 





    /* Example of the expected output format (using fake output strings) */

    strcpy(message,"themessage"); // <-- Fake (delete this when you implement your solution)
    strcpy(key,"thekey"); // <-- Fake (delete this when you implement your solution)
    strcpy(encrypted,"encryptedtext"); // <-- Fake (delete this when you implement your solution)
    strcpy(decrypted,"decryptedtext"); // <-- Fake (delete this when you implement your solution)

    //You can reuse this print statements in your solution (assuming you store each string
    //in the same variables).
    printf("Message: [%s]\n",message);
    printf("Key: [%s]\n",key);
    printf("Encrypted: [%s]\n",encrypted);
    printf("Decrypted: [%s]\n",decrypted);


    //close input.txt
    fclose(input_file);
    return 0;
}