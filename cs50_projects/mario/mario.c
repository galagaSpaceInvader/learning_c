#include <stdio.h>

int main(void) {
    int n = -1; // Haven't learnt how to accept inputs yet so we will simulate it

    while(!(n >= 1 && n <= 8)) {
        printf("The number you entered is not valid it must be bettween 1-8.\n");
        n=7; //reinput the height value 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}