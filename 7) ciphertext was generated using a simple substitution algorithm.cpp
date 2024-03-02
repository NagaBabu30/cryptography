#include <stdio.h>
#include <string.h>

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"
                        "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*"
                        ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    char decrypted[strlen(ciphertext) + 1];
    strcpy(decrypted, ciphertext);
    for (int i = 0; i < strlen(ciphertext); i++) {
        switch (ciphertext[i]) {
            case '†': decrypted[i] = 'e'; break;
            case '‡': decrypted[i] = 't'; break;
            case '¶': decrypted[i] = 'h'; break;
            case '—': decrypted[i] = 'a'; break;
            case ';': decrypted[i] = 'r'; break;
            case '5': decrypted[i] = 'o'; break;
            case '3': decrypted[i] = 'n'; break;
            case '6': decrypted[i] = 's'; break;
            case '(': decrypted[i] = 'i'; break;
            case '8': decrypted[i] = 'l'; break;
            case '4': decrypted[i] = 'f'; break;
            case '0': decrypted[i] = 'c'; break;
            case '2': decrypted[i] = 'd'; break;
            case '9': decrypted[i] = 'g'; break;
            case ']': decrypted[i] = 'u'; break;
            case ':': decrypted[i] = 'm'; break;
            case '?': decrypted[i] = 'p'; break;
            case '1': decrypted[i] = 'w'; break;
            default: break; 
        }
    }

    printf("Decrypted message: %s\n", decrypted);
    return 0;
}

