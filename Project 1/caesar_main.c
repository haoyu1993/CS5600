#include <stdio.h>
#include "caesar.h"

int main() {
    char plaintext[] = "Hello, World!";
    int key = 3;

    printf("Original text: %s\n", plaintext);

    encode(plaintext, key);
    printf("Encoded text: %s\n", plaintext);

    decode(plaintext, key);
    printf("Decoded text: %s\n", plaintext);

    return 0;
}
