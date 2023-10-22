#include <stdio.h>
#include "caesar.h"

void encode(char *plaintext, int key) {
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = 'A' + (plaintext[i] - 'a' + key) % 26;
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        }
    }
}

void decode(char *ciphertext, int key) {
    encode(ciphertext, 26 - key); // Decoding is just encoding with the reverse key
}
