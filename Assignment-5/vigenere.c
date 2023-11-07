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

    return 0;
}