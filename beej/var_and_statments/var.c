#include <stdio.h>
#include <stdbool.h> // Is needed to do booleans in all c versions other than C23
#include <stdlib.h> // This gives access to the rand function

/*
Variables are human readable names for data in memory, realistically every byte of memory can be refered to by a index
Pointers are variables that store the numerical memory adress of other variables

Nameing rules:
    1. No starting with digits
    2. No starting with two underscores
    3. No starting with a underscore followed by a caital letter


Types of Variables:
    1.Integer
        -Holds both signed and unsigned intagers
        -the c type for it 'int'
    2.Float
        -Holds both signed and unsigned decimal numbers
        -the c type for it is 'float'
    3.Character
        -Holds ascii characters
        -the c type for it is 'char'
    4.String
        -Holds a array or list of ascii characters
        -the c type for it is 'char *' or char pointer

C doesn't track variable types, if you run a function of a string like it is a int it will be treated as a ineger
For strings what it does is load a list of characters and a null terminator so functions that know to look for it can identify the end fo the string
*/


int main(void) {
    int i; // These guys are declared but they aren't used, usutally there deafult value is 0 but, it may vary so its better to allywas decalre and defign them
    float q;

    int j = 2;
    j = 5;
    char *s = "Hello";
    char c = 'c';
    float f = 21.2;

    //Printing variables
    printf("j=%d, s=%s, c=%c, f=%f\n", j, s, c, f); //%d for inagers %s for strings %c for characters and %f for floats and %d
    /*
    important to note that if I decare a pointer

    char *p = "hello"
    this creates a variable p with a memrory adress pointing to the h character

    when I do *p again after creation that derefrences or unpointers a pointer, it says go to the adress in p fetch the character and set p equal to it
    
    */

    // Okay so booleans in c true = 1,2,3 any number other than 0 is true and false = 0

    bool aBool = true;

    //code in the if will only run if the expression bettween the parenthesis is true
    if (aBool) {
        printf("aBool is True\n");
        printf("Printed aBool:%d\n", aBool);
    }

    //there are also some operators we can use to manipulate the vale of variables
     i = 3;
    i = i + 3; //Same as i += 3
    i = i - 2; //Same as i -= 2
    i = i * 1; //Same as i *= 1
    i = i / -1; //Same as i /= 1

    //the ternary opperator
    //condition?if yes use this:if no use this

    bool tern = true;
    i += tern?4:3; //if tern is true we add 4 to i if tern is false we add 3 to i
    //we can pritn content of bool liek this
    tern = false;
    printf("The content in the boolean tern is: %s\n", tern?"true":"false");

    //the comma operater  lets you do two expressions in line

    int x;
    int y;

    x=2, y=3; 

    //Conditional opperators are very easy if you want add a else if or a else and boom majic done just like python except for elif and curly braces

    if (x==2 && y==3) {
        printf("The && opperator is useed for and.\n");
    }

    if (x || y==4) {
        printf("The || operator is used for or.\n");
    }

    if (!tern) {
        printf("The ! opperator is used for not\n");
    }
    // While statments
    i = 0;
    while (i < 10) {
        printf("Round:%d\n",i);
        i++;
    }
    //This will print round 0-round 9, a total of 10 rounds stopign when i is equal to 10
    //if the condition is 1 or true it will be a infinate loop

    /*
    sometimes the counting variable be i or any other one isn't the right value comming in and one while loop has to run before the conition is applied, welcome to the wonderfull world of the do while statment
    the code bellow will increment i to 11 and ouput 10
    */
    do {
        printf("The value of i:%d\n", i);
        i++;
    } while (i < 10);

    int r;

    do {
        r = rand() % 100;
        printf("R:%d\n",r);
    } while (r != 37);

    // above I made a for loop with a while loop now for the real for loop
    // for (initialize things; loop if this is true; do this after each loop), if you leave the loop empty just with ;; it will run forever
    // you can do multiple things ina loop using the , operator
    for (i = 0; i < 10; i++) {
        printf("Round:%d\n",i);
    }
    //switch stament, basically its just is this thing in the switch parenthesis is equal to the thing next to the case
    int waterbottle = 2002;
    switch (waterbottle) {
        case 1:
            printf("Waterbottle is 1\n");
            break;
        case 2:
            printf("Waterbottle is 2\n");
            break;
        case 2002:
            printf("Waterbottle is 2002\n");
            break;
    };
    //if you don't have the breaks it will jump to the instruction in the next case without the switch state needs to be true


    // There is a way to measure the space in memory take up by a variable or expression, this is the sizeof opperator
    // The output of size is not a int rather its a speccial type just for this use called size_t, a unsigned type that can hold a size in bytes output by the operator
    // to print size_t use %zu
    printf("Size of tern:%zu\n",sizeof(tern));
    printf("Size of y:%zu\n",sizeof(y)); //size of the type not size of expression, so sizeof is a compile time opperation since in c types are determined at compile type rather than at execution time
}