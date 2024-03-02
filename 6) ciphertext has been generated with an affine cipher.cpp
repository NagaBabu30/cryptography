#include <stdio.h>

int main() {
    char mostFreq, secondFreq;
    printf("Enter most and second most frequent letters: ");
    scanf(" %c %c", &mostFreq, &secondFreq);

    int a = (secondFreq - mostFreq + 26) % 26;
    int b = (mostFreq - 'A' - a * ('B' - 'A')) % 26;

    printf("Key values: a = %d, b = %d\n", a, b);

    return 0;
}

