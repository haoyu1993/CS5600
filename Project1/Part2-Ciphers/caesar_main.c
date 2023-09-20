#include <stdio.h>
#include <string.h>
#include "caesar.h"

int main() {
    char text[100]; // Assume a maximum input text length of 100 characters
    int key = 3;    // Specify a fixed key value

    // Get user input text
    printf("Enter a text: ");
    scanf("%99[^\n]%*c", text); // Read a line of text from user input

    printf("Original Text: %s\n", text);

    // Encrypt
    encode(text, key);
    printf("Encoded Text: %s\n", text);

    // Decrypt
    decode(text, key); // Use the same key for decryption
    printf("Decoded Text: %s\n", text);

    return 0;
}
