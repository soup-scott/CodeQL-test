#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 32 bytes perfectly overflows eip
// 239 bytes is the size of the buffer + address + NOP sled + shell
size_t INPUT_SIZE = 239;

int bufover(char* overload) {
    char buf[16];
    strcpy(buf, overload);

    return 1;
}

int main() {
    char badInput[INPUT_SIZE];
    FILE* badFile;

    badFile = fopen("payload.bin", "r");
    fread(badInput, sizeof(char), INPUT_SIZE, badFile);
    bufover(badInput);
    printf("executed\n");

    return 0;
}

// gcc -m32 -z execstack -fno-stack-protector -vuln-buf-over.c -o vuln