#include<stdio.h>

int main() {
    unsigned int a[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    unsigned int b[3][3] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};
    unsigned int c[3], d[3];
    char msg[4];

    printf("Enter a 3-character message (uppercase letters only): ");
    scanf("%3s", msg);

    for (int i = 0; i < 3; i++) {
        c[i] = msg[i] - 'A';
    }

    printf("Encrypted Cipher Text: ");
    for (int i = 0; i < 3; i++) {
        d[i] = (a[i][0] * c[0] + a[i][1] * c[1] + a[i][2] * c[2]) % 26;
        printf("%c", d[i] + 'A');
    }

    printf("\nDecrypted Cipher Text: ");
    for (int i = 0; i < 3; i++) {
        c[i] = (b[i][0] * d[0] + b[i][1] * d[1] + b[i][2] * d[2]) % 26;
        printf("%c", c[i] + 'A');
    }

    return 0;
}


