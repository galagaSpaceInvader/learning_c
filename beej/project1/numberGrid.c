#include <stdio.h>


int main(void) {
    int n = 25;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", (i+1)*(j+1)); //so what this does is insert the number and it reserves three spaces for the number that is being prinder if not used creates a empty character or a space allowing corect number alignment
        }
        printf("\n");
    }
}