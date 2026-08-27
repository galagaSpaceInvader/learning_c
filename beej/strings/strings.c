#include <stdio.h>
#include <string.h> // Gives access to string related functions

int main(void) {
    // In c strings barely exist they are also syntactic sugar much liek strings, under the hood they are pointers
    // When we refer to strings they are a sequence of characters in double qoutes

    char *s = "Hello, World\n"; // This is a string, at the end of the day strings=array of characters which is deeply connected with pointers, specifically its like setting a array equal to a pointer this is &a[0] 
    printf("%s", s);

    char s2[] = "Hello, World\n";
    printf("%s", s); // In this case array decays to a pointer &s2[0] and boom bada boom

    // even if we inicicallize as a pointer we can use array stuff to read it
    for (int i = 0; i < 14; i++) {
        printf("%c\n", s[i]);
    }
    /* 
    the above code works because when you use this notation s[i] the computer auto decays the s to a pointer to the first element of the array if it is a arrya
    then converts it to *(s+i), so we are adding lengths of elements to s to find the adress of consecutive elemnts and then derefrencing them

    yet there is a diffrence when you inicialize a string as a pointer since it takes up so much memory c banishes the bytes far from the program to optimize the code, read only memory, so if its inicialized as pointer the strign can not be mutated, undefigned behaviour were the compiler could tell the code to do anything

    */

    //length of strings you just have to loop till you hit the null terminator or use strlen, it outputs a size_t value or a amount of bytes, since a char is 1 byte its also the amount of chars

    printf("The length is: %zu\n",strlen(s2));

    // Finnaly copying strings is hard since you can jsut set = becuase that will jsut copy the pointer to the first element
    // thus use strcpy
    char t[100];
    strcpy(t,s);
    printf("%s\n",t);
}