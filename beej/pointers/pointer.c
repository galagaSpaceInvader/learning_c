#include <stdio.h>

int decrement(int *p);

int main(void) {
    // Every byte in memory is represened by sequencially increasing ingers, this number is a memory ADRESS
    // Yet not all types use exactly 1 byte in memory
    printf("In fact the size of a ineger happens to be:%zu, which is no 1 byte in memory.\n", sizeof(int)); // Something to note is that while most systems order stuff int he order you would expect in memory some systems don't and write it in reverse order?
    // A pointer is a varable that holds a memroy adress
    // The "adress of" operator for getting the adress of a variable is the &
    int a = 2;
    int *p = &a; //Thus the variable p stores the pointer to the varaible a's content of 2 in memory
    // The * indicates that the newly created variable is a pointer, specifically due to the int * it is a pointer to a intager

    printf("The value of a is:%d\n", a);
    printf("The adress to the value stored in a is:%p.\n", &a); // This will give a huge number that does no mean we have this huge number of bytes in memory because our computer uses virutal memory to make applications feel like they have all the space they need and then it allocates it to some lower level in  system meory

    // You can never the less still get access to tthe orginal varable and make changes to it by way of the pointer, using the derefrence opperator anemly:
    printf("a is using only the pointer:%d\n", *p);
    a = 3;
    printf("a is:%d\n", a);
    *p =  1;
    printf("After changing a using the derefrence operator we are left with a value of:%d\n",a);
    // And P still stores the adress nothign has changed

    // more unbelibale is that if we pass the variable p into the decrement function it can still pass a return value back and stil update p ever nothought the p in the function is a aprameter a copy of the original p
    printf("After decrement valye of a:%d\n", decrement(p));

    //if a pointer has a value of NULL then it means its not pointed at anythign, you should not be derefrencing such a variable
    
}

int decrement(int *p) {
    *p = *p - 1;
    return *p;
}