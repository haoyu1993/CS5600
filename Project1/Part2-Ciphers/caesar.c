#include <ctype.h>
#include "caesar.h"

// Function to encode the plaintext using the Caesar cipher
void encode(char *plaintext, int key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) { // Check if the character is a letter
            char base = islower(plaintext[i]) ? 'a' : 'A'; // Determine the base (lowercase or uppercase)
            plaintext[i] = ((plaintext[i] - base + key) % 26) + base; // Apply the Caesar cipher encryption
        }
    }
}

// Function to decode the ciphertext using the Caesar cipher
void decode(char *ciphertext, int key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) { // Check if the character is a letter
            char base = islower(ciphertext[i]) ? 'a' : 'A'; // Determine the base (lowercase or uppercase)
            ciphertext[i] = ((ciphertext[i] - base - key + 26) % 26) + base; // Apply the Caesar cipher decryption
        }
    }
}
