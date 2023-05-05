#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *message, int key);

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int key)
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
                ch = (ch + key - 'A') % 26 + 'A';
            }
            else 
            {
                ch = (ch + key - 'a') % 26 + 'a';
            }

            message[i] = ch;
        }
    }
}
