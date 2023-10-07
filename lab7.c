#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Initialize a flag to indicate whether num2 is the multiplicative inverse of num1
    int isMultiplicativeInverse = 0;

    // Check if num2 is the multiplicative inverse of num1
    for (int i = 1; i <= 1000; i++) {
        if (num1 * i == 1 && num2 * i == 1) {
            isMultiplicativeInverse = 1;
            break;
        }
    }

    // Check the flag and display the result
    if (isMultiplicativeInverse) {
        printf("%d is the multiplicative inverse of %d\n", num2, num1);
    } else {
        printf("%d is not the multiplicative inverse of %d\n", num2, num1);
    }

    return 0;
}

