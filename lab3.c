#include <stdio.h>
#include <string.h>

void vigenere_encrypt(char *plain_text, char *key) {
    int text_len = strlen(plain_text);
    int key_len = strlen(key);
    char encrypted_text[text_len + 1];

    for (int i = 0; i < text_len; i++) {
        if (plain_text[i] >= 'a' && plain_text[i] <= 'z') {
            encrypted_text[i] = 'a' + (plain_text[i] - 'a' + key[i % key_len] - 'A') % 26;
        } else if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
            encrypted_text[i] = 'A' + (plain_text[i] - 'A' + key[i % key_len] - 'A') % 26;
        } else {
            encrypted_text[i] = plain_text[i];
        }
    }

    encrypted_text[text_len] = '\0';
    printf("Encrypted Text: %s\n", encrypted_text);
}

void vigenere_decrypt(char *encrypted_text, char *key) {
    int text_len = strlen(encrypted_text);
    int key_len = strlen(key);
    char decrypted_text[text_len + 1];

    for (int i = 0; i < text_len; i++) {
        if (encrypted_text[i] >= 'a' && encrypted_text[i] <= 'z') {
            decrypted_text[i] = 'a' + (encrypted_text[i] - 'a' - (key[i % key_len] - 'A') + 26) % 26;
        } else if (encrypted_text[i] >= 'A' && encrypted_text[i] <= 'Z') {
            decrypted_text[i] = 'A' + (encrypted_text[i] - 'A' - (key[i % key_len] - 'A') + 26) % 26;
        } else {
            decrypted_text[i] = encrypted_text[i];
        }
    }

    decrypted_text[text_len] = '\0';
    printf("Decrypted Text: %s\n", decrypted_text);
}

int main() {
    char plain_text[] = "web development!";
    char key[] = "KEY";

    printf("Plain Text: %s\n", plain_text);
    printf("Key: %s\n", key);

    vigenere_encrypt(plain_text, key);
    vigenere_decrypt("Rovvy, Gybvn!", key); // Example decryption

    return 0;
}

