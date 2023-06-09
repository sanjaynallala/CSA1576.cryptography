#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000
#define NUM_LETTERS 26

void count_letters(char *text, int *count) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            count[tolower(text[i]) - 'a']++;
        }
    }
}

void shift_text(char *text, int shift) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            text[i] = ((tolower(text[i]) - 'a' + shift) % NUM_LETTERS) + 'a';
        }
    }
}

int compare_letter_count(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

void guess_plaintext(char *ciphertext, int num_plaintexts) {
    int letter_count[NUM_LETTERS] = {0};
    count_letters(ciphertext, letter_count);

    int letter_freq[NUM_LETTERS] = {
        8, 1, 3, 4, 12, 2, 2, 6, 7, 0, 1, 4, 2, 7, 8,
        2, 0, 6, 6, 9, 3, 1, 2, 0, 2, 0
    };

    int shift_counts[NUM_LETTERS];
    for (int shift = 0; shift < NUM_LETTERS; shift++) {
        shift_counts[shift] = 0;
        shift_text(ciphertext, shift);
        int plaintext_letter_count[NUM_LETTERS] = {0};
        count_letters(ciphertext, plaintext_letter_count);
        for (int i = 0; i < NUM_LETTERS; i++) {
            shift_counts[shift] += letter_freq[i] * plaintext_letter_count[i];
        }
        shift_text(ciphertext, NUM_LETTERS - shift);
    }

    int shift_order[NUM_LETTERS];
    for (int i = 0; i < NUM_LETTERS; i++) {
        shift_order[i] = i;
    }

    qsort(shift_order, NUM_LETTERS, sizeof(int), compare_letter_count);

    printf("Possible plaintexts:\n");
    for (int i = 0; i < num_plaintexts; i++) {
        printf("%d. ", i + 1);
        int shift = shift_order[i];
        shift_text(ciphertext, shift);
        printf("%s\n", ciphertext);
        shift_text(ciphertext, NUM_LETTERS - shift);
    }
}

int main() {
    char ciphertext[MAX_TEXT_LENGTH];
    printf("Enter ciphertext: ");
    fgets(ciphertext, MAX_TEXT_LENGTH, stdin);

    int num_plaintexts;
    printf("Enter number of possible plaintexts to output: ");
    scanf("%d", &num_plaintexts);

    guess_plaintext(ciphertext, num_plaintexts);

    return 0;
}
