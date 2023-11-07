/* vigenere.c
   CSC 111 - Fall 2023 - Assignment 5


   B. Bird - 2023-10-26
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

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

void read_input(char* filename, char** key, char** message) {
        FILE* input_file = fopen(filename,"r");
        if (!input_file){
            printf("Error: Unable to open input file.\n");
            exit(1);
        }

        // Allocate memory for key and message
        *key = malloc(100 * sizeof(char));
        *message = malloc(100 * sizeof(char));

        // Read in key and message
        if (fgets(*key, 100, input_file) == NULL) {
            printf("Error: Unable to read key from input file.\n");
            exit(1);
        }
        if (fgets(*message, 100, input_file) == NULL) {
            printf("Error: Unable to read message from input file.\n");
            exit(1);
        }

        // Remove newline characters from key and message
        (*key)[strcspn(*key, "\n")] = 0;
        (*message)[strcspn(*message, "\n")] = 0;

        fclose(input_file);
    }


int vigenere(char* key, char* message, char* encrypted, char* decrypted){
    //open input.txt
    read_input("input.txt", key, message);
    //if the key has length of 0, throw an invalid key error. 
    if (strlen(key) <= 0){
        printf("Error: Invalid Key.\n");
        return 1; 
    }

    //if the message has a length of 0, OR contains any non-lowercase characters, throw an invalid message error. 
    if (strlen(message) <= 0){
        printf("Error: Invalid message.\n");
        return 1; 
    }

    for (int i = 0; i < strlen(message); i++){
        //this might walk off the end of the string, I have no idea
        if (islower(message[i]) == 0)
        {
            //if we get in here we throw errors broski
            printf("Error: b Invalid message. Character [%c], on index %d, is invalid.\n", message[i], i);
            return 1; 
        }
    }
//if we get here, we can rest assured both the message and the key are valid. 
    //encyrpt the message, using the vigenere cipher.

    //expand the key to repeat itself for the length of the message. 
    int key_counter = 0;
    for (int i = 0; i < strlen(message); i++){
        //if we get to the end of the key, we will reset the counter to 0. 
        if (key_counter == strlen(key)){
            key_counter = 0;
        }
        //we will set the current character of the key to the current character of the message.
        key[i] = key[key_counter];
        //increment the counter
        key_counter++;
    }

    //encrypt the message
    //this is really just adding the index of the key to the index of the message, and then modding by 26.
    for (int i = 0; i < strlen(message); i++){
        //we will add the index of the key to the index of the message, and then mod by 26.
        encrypted[i] = index_to_character((character_to_index(message[i]) + character_to_index(key[i])) % 26);
    }
    //append a null terminator to the position of the newline to the encrypted message.
    encrypted[strcspn(encrypted, "\n")] = 0;

    //decrypt the message
    //lets convert the each character of the encypted message back to the index. 
    for (int i = 0; i < strlen(encrypted); i ++){
        //start by converting each character of encrypted to the index.
        int encrypted_index = character_to_index(encrypted[i]);
        //next, convert the corresponding character of the key to the index. 
        int key_index = character_to_index(key[i]);
        //now, we will subtract the key index from the encrypted index.
        int decrypted_index = (encrypted_index - key_index);
        //if the decrypted index is negative, we will add 26 to it.
        if (decrypted_index < 0){
            decrypted_index += 26;
        }
        //now, we will mod the decrypted index by 26.
        decrypted_index = decrypted_index % 26;
      //  printf("%d\n", decrypted_index);
        //convert this index to a character and save it to the decrypted buffer
        decrypted[i] = index_to_character(decrypted_index);

    }






    /* Example of the expected output format (using fake output strings) */

    //strcpy(message,"themessage"); // <-- Fake (delete this when you implement your solution)
    //strcpy(key,"thekey"); // <-- Fake (delete this when you implement your solution)
    //strcpy(encrypted,"encryptedtext"); // <-- Fake (delete this when you implement your solution)
    //strcpy(decrypted,"decryptedtext"); // <-- Fake (delete this when you implement your solution)

    //You can reuse this print statements in your solution (assuming you store each string
    //in the same variables).
    printf("Message: [%s]\n",message);
    printf("Key: [%s]\n",key);
    printf("Encrypted: [%s]\n",encrypted);
    printf("Decrypted: [%s]\n",decrypted);


    //close input.txt
    //fclose(input_file);
    return 0;
}

void test_vigenere(){
  char encrypted[100];
  char decrypted[100];
  
  
  // Test with valid key and message
    char* key1 = "key";
    char* message1 = "message";
    assert(vigenere(key1, message1, encrypted, decrypted) == 0);

    // Test with empty key
    char* key2 = "";
    char* message2 = "message";
    assert(vigenere(key2, message2, encrypted, decrypted) == 1);

    // Test with empty message
    char* key3 = "key";
    char* message3 = "";
    assert(vigenere(key3, message3, encrypted, decrypted) == 1);

    // Test with non-lowercase characters in message
    char* key4 = "key";
    char* message4 = "Message";
    assert(vigenere(key4, message4, encrypted, decrypted) == 1);

    // Test with non-alphabetic characters in key
    char* key5 = "k3y";
    char* message5 = "message";
    assert(vigenere(key5, message5, encrypted, decrypted) == 1);
}



int main() {

    test_vigenere();

    return 0;
}