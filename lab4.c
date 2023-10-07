#include <stdio.h>
#include <string.h>

// Function to remove spaces and duplicate letters from the key
void prepareKey(char *key) {
    int i, j;
    int len = strlen(key);
    int unique[26] = {0};
    
    for (i = 0, j = 0; i < len; i++) {
        if (key[i] != ' ') {
            if (!unique[key[i] - 'A']) {
                key[j++] = key[i];
                unique[key[i] - 'A'] = 1;
            }
        }
    }
    
    for (; j < 26; j++) {
        for (i = 0; i < 26; i++) {
            if (!unique[i]) {
                key[j++] = 'A' + i;
                unique[i] = 1;
            }
        }
    }
    key[j] = '\0';
}

// Function to create the Playfair cipher matrix
void createMatrix(char key[], char matrix[5][5]) {
    int i, j, k = 0;
    int len = strlen(key);
    int used[26] = {0};
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            while (used[key[k] - 'A'] || key[k] == 'J') {
                k++;
            }
            matrix[i][j] = key[k];
            used[key[k] - 'A'] = 1;
            k++;
        }
    }
}

// Function to find the position of a letter in the matrix
void findPosition(char matrix[5][5], char letter, int *row, int *col) {
    int i, j;
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a digraph using Playfair cipher
void encrypt(char matrix[5][5], char a, char b) {
    int row1, col1, row2, col2;
    
    findPosition(matrix, a, &row1, &col1);
    findPosition(matrix, b, &row2, &col2);
    
    if (row1 == row2) {
        col1 = (col1 + 1) % 5;
        col2 = (col2 + 1) % 5;
    } else if (col1 == col2) {
        row1 = (row1 + 1) % 5;
        row2 = (row2 + 1) % 5;
    } else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }
    
    printf("%c%c%c%c", matrix[row1][col1], matrix[row2][col2], matrix[row1][col2], matrix[row2][col1]);
}

int main() {
    char key[30];
    char plaintext[100];
    char matrix[5][5];
    
    printf("Enter the key (no spaces, only uppercase letters): ");
    scanf("%s", key);
    
    prepareKey(key);
    createMatrix(key, matrix);
    
    printf("Enter the plaintext (uppercase letters only): ");
    scanf("%s", plaintext);
    
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 2) {
        if (i == len - 1) {
            // If there is an odd number of letters, append 'X' to make it even
            printf("%cX", plaintext[i]);
        } else {
            encrypt(matrix, plaintext[i], plaintext[i + 1]);
        }
    }
    
    return 0;
}

