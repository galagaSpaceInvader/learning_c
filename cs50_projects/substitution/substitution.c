#include <stdio.h>
#include <ctype.h>

int strlength(char *s);

int main(int argc, char *argv[]) {
    if (argc == 2) {
        char plainText[] = "Hello";
        char *key = argv[1];
        char c = 'a';
        int alpha = 1;
        int repet = 0;
        for (int i = 0; c != '\0'; i++) {
            c = key[i];
            if (!isalpha(c) && c != '\0') {
                alpha = 0;
                break;
            }
            for (int j = 0; j < i + 1; j++) {
                if (tolower(key[j]) == tolower(c) && j != i) {
                    repet = 1;
                    break;
                }
            }
        }
        if (strlength(key) != 26) {
            printf("Ensure that the key you insert into this function as a argument is exactly 26 characters long.\n");
            return 1;
        } else if (alpha == 0) {
            printf("Ensure that the key you insert into this function as a argument is composed of only alphabetical characters.\n");
            return 1;
        } else if (repet == 1) {
            printf("Ensure that the key you insert into this function as a argument is composed of non-repeating characters.\n");
            return 1;
        } else {
            int lenPlain = strlength(plainText);
            char encrypted[lenPlain + 1];
            encrypted[lenPlain] = '\0';
            for (int i = 0; i < lenPlain; i++) {
                c = tolower(plainText[i]) - 'a';
                if (isupper(plainText[i])) {
                    encrypted[i] = toupper(key[c]);
                } else {
                    encrypted[i] = key[c];
                }
            }
            printf("Plaintext:%s\n", plainText);
            printf("Encrypted:%s\n", encrypted);
            return 0;
        }
    } else {
        printf("Please submit but a single argument to the code using the following usage:\n ./substitution.c [a 26 character long key without repetitions used for the encryption].\n");
        return 1;
    }
    
}

int strlength(char *s) {
    int i = 0;
    char c = 'a';
    for (; c != '\0'; i++) {
        c = s[i];
    }
    return i-1;
}