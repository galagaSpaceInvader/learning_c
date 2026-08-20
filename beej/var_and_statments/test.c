#include <stdio.h>

int main(void) {
    char c = 'A';
    
    // if promotion was NOT happening and printf was reading raw memory
    // like the pointer case, youd get a garbage number like 154353473
    // but instead you get:
    printf("%d\n", c);
    
    // and you can confirm the promotion by doing it manually yourself
    // and seeing you get the exact same result
    int promoted = c;
    printf("%d\n", promoted);
    
    return 0;
}