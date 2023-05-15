#include <stdio.h>
#include <string.h>

void encrypt(char* plaintext, char* key) {
    int i, j, k;
    int n = strlen(plaintext);
    int m = strlen(key);
    char ciphertext[n];

    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == m) {
            j = 0;
        }
        k = (plaintext[i] + key[j] - 2 * 'a') % 26;
        ciphertext[i] = k + 'a';
    }

    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char* ciphertext, char* key) {
    int i, j, k;
    int n = strlen(ciphertext);
    int m = strlen(key);
    char plaintext[n];

    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == m) {
            j = 0;
        }
        k = (ciphertext[i] - key[j] + 26) % 26;
        plaintext[i] = k + 'a';
    }

    printf("Plaintext: %s\n", plaintext);
}

int main() {
    char plaintext[] = "sendmoremoney";
    char key[] = "90172315211411289";
    encrypt(plaintext, key);

    char ciphertext[] = "zlsokdxpflil";
    char target[] = "cashnotneeded";

    printf("Target: %s\n", target);

    char key2[strlen(key)];
    for (int i = 0; i < strlen(key); i++) {
        key2[i] = ((target[i] - ciphertext[i] + 26) % 26) + 'a';
    }
    key2[strlen(key)] = '\0';

    printf("Key: %s\n", key2);
    decrypt(ciphertext, key2);

    return 0;
}
