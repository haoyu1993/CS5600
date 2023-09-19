#include <ctype.h>
#include "caesar.h"

void encode(char *plaintext, int key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            plaintext[i] = ((plaintext[i] - base + key) % 26) + base;
        }
    }
}

void decode(char *ciphertext, int key) {
    encode(ciphertext, 26 - key); // 解密与加密相反，使用反向的密钥
}
