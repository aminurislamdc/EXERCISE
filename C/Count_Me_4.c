#include <stdio.h>

int main() {
    char s[10001]; // Given constraints: max length is 10,000
    int freq[26] = {0}; // Array to store frequencies of 'a' to 'z'

    scanf("%s", s); // Input string

    // Count occurrences
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Print non-zero frequencies in sorted order
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c - %d\n", i + 'a', freq[i]);
        }
    }

    return 0;
}