#include <stdio.h>

/*The above include tells the c pre proccessor to go look for the file and insert it there. All comands followed by a hashtag are preproccessor directives*/
//Bascially what happens if that the function propositions are inseted into the top of the file and at the same time the linker joins the necessary compilded c code for the functions to the executabel whether it be a stanard libary or not it goes looking for the compiled printf lets say
//two types of linking static which joins the neccesary code to the executbale and dynamic were the neccesary code comes from the system were the code is executed
//The C preproccessor makes changes before compilation to the code

int main(void) { //This is the entrence to every c program, the int and void mean a int is refurned after execution a 0 for success and void is saying no flags or arguments are bing taken by the code
    printf("Hello World!\n");//This is a function we are running and passing in argument to be rprinted to screen, the slash n is a escape character that elts you create white space tabs and such
}

/*
Code will be compiled with:
gcc -o hello hello.c

the gcc is the c compiler -o dictates the name of the output executable and hello.c is the file that should be compiled, we only hev one file but we can compile a it f¡if c code into 1 by listing it after, .h files fr each has to be in the compilation directory
we can use this tag to specify what c version to use -std=c23
to enable more debug use -pedantic -Wall -Wextra
*/