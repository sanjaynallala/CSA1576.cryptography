#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main()
{
    char message[100];
    char key[27];

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key (26 letters): ");
    fgets(key, sizeof(key), stdin);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, char *key)
{
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; i++) 
    {
        ch = message[i];

        if (isalpha(ch)) 
        {
            if (isupper(ch)) 
            {
                message[i] = toupper(key[ch - 'A']);
            }
            else 
            {
                message[i] = tolower(key[ch - 'a']);
            }
        }
    }
}

void decrypt(char *message, char *key)
{
    int i, j;
    char ch;

    char plain_key[26] = "abcdefghijklmnopqrstuvwxyz";
    char cipher_key[26];

    // Create cipher key from provided key
    for (i = 0; i < 26; i++) 
    {
        cipher_key[i] = tolower(key[i]);
    }

    for (i = 0; message[i] != '\0'; i++) 
    {
        ch = message[i];

        if (isalpha(ch)) 
        {
            if (isupper(ch)) 
            {
                for (j = 0; j < 26; j++) 
                {
                    if (cipher_key[j] == tolower(ch)) 
                    {
                        message[i] = toupper(plain_key[j]);
                        break;
                    }
                }
            }
            else 
            {
                for (j = 0; j < 26; j++) 
                {
                    if (cipher_key[j] == ch) 
                    {
                        message[i] = plain_key[j];
                        break;
                    }
                }
            }
        }
    }
}

