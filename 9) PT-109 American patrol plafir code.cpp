#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 5

// Function to find the position of a character in the key square
void findPosition(char keySquare[ROWS][COLS], char letter, int *row, int *col) {
    if (letter == 'J') // Replacing J with I
        letter = 'I';
    
    for (*row = 0; *row < ROWS; (*row)++) {
        for (*col = 0; *col < COLS; (*col)++) {
            if (keySquare[*row][*col] == letter) {
                return;
            }
        }
    }
}

// Function to decode the Playfair cipher
void decodePlayfair(char keySquare[ROWS][COLS], char *message) {
    int row1, col1, row2, col2;
    int i;

    for (i = 0; i < strlen(message); i += 2) {
        // Finding positions of each pair of letters in the message
        findPosition(keySquare, message[i], &row1, &col1);
        findPosition(keySquare, message[i + 1], &row2, &col2);

        // Same row
        if (row1 == row2) {
            printf("%c%c", keySquare[row1][(col1 + 4) % 5], keySquare[row2][(col2 + 4) % 5]);
        }
        // Same column
        else if (col1 == col2) {
            printf("%c%c", keySquare[(row1 + 4) % 5][col1], keySquare[(row2 + 4) % 5][col2]);
        }
        // Different row and column
        else {
            printf("%c%c", keySquare[row1][col2], keySquare[row2][col1]);
        }
    }
    printf("\n");
}

int main() {
    char keySquare[ROWS][COLS] = {
        {'K', 'X', 'J', 'E', 'Y'},
        {'U', 'R', 'E', 'B', 'E'},
        {'Z', 'W', 'E', 'H', 'E'},
        {'W', 'R', 'Y', 'T', 'U'},
        {'H', 'E', 'Y', 'F', 'S'}
    };

    char message[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";

    printf("Decoded message: ");
    decodePlayfair(keySquare, message);

    return 0;
}

