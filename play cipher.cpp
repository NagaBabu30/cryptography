#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generateMatrix(char key[], char matrix[][SIZE]) {
    int i, j, k, flag = 0;
    int key_len = strlen(key), key_table[26] = {0};
    for (i = 0; i < key_len; ++i)
        if (key[i] != 'j' && !key_table[key[i] - 'a'])
            key_table[key[i] - 'a'] = 1, matrix[flag / SIZE][flag % SIZE] = key[i], flag++;
    for (i = 0; i < 26; ++i)
        if (!key_table[i] && i != ('j' - 'a'))
            matrix[flag / SIZE][flag % SIZE] = i + 'a', flag++;
}

void findPosition(char matrix[][SIZE], char ch, int *row, int *col) {
    if (ch == 'j') ch = 'i';
    for (*row = 0; *row < SIZE; ++(*row))
        for (*col = 0; *col < SIZE; ++(*col))
            if (matrix[*row][*col] == ch) return;
}

void encryptPair(char matrix[][SIZE], char a, char b, char *encrypted) {
    int r1, c1, r2, c2;
    findPosition(matrix, a, &r1, &c1);
    findPosition(matrix, b, &r2, &c2);
    if (r1 == r2) encrypted[0] = matrix[r1][(c1 + 1) % SIZE], encrypted[1] = matrix[r2][(c2 + 1) % SIZE];
    else if (c1 == c2) encrypted[0] = matrix[(r1 + 1) % SIZE][c1], encrypted[1] = matrix[(r2 + 1) % SIZE][c2];
    else encrypted[0] = matrix[r1][c2], encrypted[1] = matrix[r2][c1];
}

void encrypt(char matrix[][SIZE], char plaintext[], char encrypted[]) {
    int i, j = 0;
    for (i = 0; i < strlen(plaintext); i += 2)
        encryptPair(matrix, plaintext[i], plaintext[i + 1], &encrypted[j]), j += 2;
    encrypted[j] = '\0';
}

int main() {
    char key[50], plaintext[100], encrypted[100], matrix[SIZE][SIZE];
    printf("Enter the key: "); scanf("%s", key);
    printf("Enter the plaintext: "); scanf("%s", plaintext);
    generateMatrix(key, matrix);
    encrypt(matrix, plaintext, encrypted);
    printf("Encrypted text: %s\n", encrypted);
    return 0;
}

