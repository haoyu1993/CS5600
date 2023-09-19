#include <stdio.h>
#include <string.h>
#include "caesar.h"

int main() {
    char text[] = "Hello, World!";
    int key = 3;

    printf("Original Text: %s\n", text);

    // 加密
    encode(text, key);
    printf("Encoded Text: %s\n", text);

    // 解密
    decode(text, key);
    printf("Decoded Text: %s\n", text);

    return 0;
}
