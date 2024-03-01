#include <stdio.h>
#include <ctype.h>

void caesarCipher(char text[], int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            printf("%c", ((text[i] - offset + key) % 26) + offset);
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

int main() {
    char text[100];
    printf("Enter the text to encrypt: ");
    fgets(text, sizeof(text), stdin);

    printf("Caesar Cipher Encryption:\n");
    for (int key = 1; key <= 25; key++) {
        printf("Key %d: ", key);
        caesarCipher(text, key);
    }

    return 0;
}



