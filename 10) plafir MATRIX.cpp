#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char playfair[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'J'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

void prepareMessage(char *message) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] == 'J')
            message[i] = 'I';
        else
            message[i] = toupper(message[i]);
    }
}

void findPosition(char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (playfair[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char *message) {
    int i, row1, col1, row2, col2;
    for (i = 0; i < strlen(message); i += 2) {
        findPosition(message[i], &row1, &col1);
        findPosition(message[i + 1], &row2, &col2);
        if (row1 == row2) {
            message[i] = playfair[row1][(col1 + 1) % SIZE];
            message[i + 1] = playfair[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            message[i] = playfair[(row1 + 1) % SIZE][col1];
            message[i + 1] = playfair[(row2 + 1) % SIZE][col2];
        } else {
            message[i] = playfair[row1][col2];
            message[i + 1] = playfair[row2][col1];
        }
    }
}

int main() {
    char message[] = "Must see you over Cadogan West. Coming at once";
    
    prepareMessage(message);
    encrypt(message);
    
    printf("Encrypted Message: %s\n", message);
    
    return 0;
}


