#include <stdio.h>

int plus1(int n); //I like having my functions bellow main so I put a function prototype so the compuler doesn't freak out when it gets to plus1 call and know the function is defigned somewere, its a implicit declaration

int main(void) {//the void in the main function indicates that no arguments are expected
    printf("1+1=%d\n", plus1(1)); //here I am doing a function call
}

int plus1(int n) { //this is me defigning a new function, the int ont the lef of the gunction name indicats the type returned by teh function while the int n says that the function expects a parameter n of type int
    return n+1;
}