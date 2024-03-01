#include <stdio.h>

void affineCipherEncrypt(int a, int b, char plaintext[]) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        if ('a' <= c && c <= 'z')
            printf("%c", 'a' + ((a * (c - 'a') + b) % 26 + 26) % 26);
        else if ('A' <= c && c <= 'Z')
            printf("%c", 'A' + ((a * (c - 'A') + b) % 26 + 26) % 26);
        else
            printf("%c", c);
    }
    printf("\n");
}

int main() {
    char plaintext[100];
    int a, b;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the values of a and b (space separated): ");
    scanf("%d %d", &a, &b);

    affineCipherEncrypt(a, b, plaintext);

    return 0;
}



