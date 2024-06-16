#include <stdio.h>

int main() {
    char str[100];
    int count[256] = {0}; // Array to store character frequencies
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Use fgets to safely read input string

    // Iterate through the string to calculate character frequencies
    for (i = 0; str[i] != '\0'; i++) {
        count[(int)str[i]]++; // Increment count for the current character
    }

    printf("Character frequencies:\n");

    // Print frequencies of characters that appear at least once
    for (i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("%c: %d\n", (char)i, count[i]);
        }
    }

    return 0;
}

