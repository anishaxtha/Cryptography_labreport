#include <stdio.h>
#include <string.h>

// Function to perform the shift cipher encryption or decryption
void shiftCipher(char *text, int shift, int encrypt) {
    int i;

    for (i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            if (encrypt)
                text[i] = 'a' + (c - 'a' + shift) % 26;
            else
                text[i] = 'a' + (c - 'a' - shift + 26) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            if (encrypt)
                text[i] = 'A' + (c - 'A' + shift) % 26;
            else
                text[i] = 'A' + (c - 'A' - shift + 26) % 26;
        }
    }
}

int main() {
    char text[1000];
    int shift, choice;

    printf("Enter the text: ");
    gets(text);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1) {
        shiftCipher(text, shift, 1);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        shiftCipher(text, shift, 0);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice. Please enter 1 for encryption or 2 for decryption.\n");
    }

    return 0;
}

