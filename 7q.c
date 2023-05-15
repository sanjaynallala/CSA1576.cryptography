#include <stdio.h>
#include <string.h>

int main() {
    char ciphertext[] = "Lwlyplzlhy jpwoly! Lujlcpnohtl ohz jolhunl pz jpwolyz.";
    char plaintext[1000]; 
    char key[27] = "qwertyuiopasdfghjklzxcvbnm";
    int i, j;

    for (i = 0; i < strlen(ciphertext); i++) {
       
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            
            for (j = 0; j < 26; j++) {
                if (key[j] == ciphertext[i]) {
                    plaintext[i] = 'a' + j; 
                    break;
                }
            }
        } else {
            plaintext[i] = ciphertext[i]; 
        }
    }

    printf("Decoded plaintext: %s\n", plaintext);

    return 0;
}
