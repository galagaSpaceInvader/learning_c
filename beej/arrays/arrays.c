#include <stdio.h>

int main(void) {
    // Arrays kinda exist in c, but actually not really
    double f[4]; //Array of 4 floats, when you create a array you always have to provide this and then its fixed you can not change the lenght of the array
    f[0] = 3.1415926535; // I cna index the elements in the array
    f[1] = 9.81;
    f[2] = 2.71;
    f[3] = 67.67;

    for (int i = 0; i < 4; i++) {
        printf("%f\n", f[i]);
    }
    // Since c is so helpfull it doesn't store the length of arrays but we can kind of sorta find it, or yuo have to manage it ina nother variable
    printf("%zu\n", sizeof(f));
    printf("%zu\n", sizeof(double));

    printf("%zu\n", sizeof(f)/sizeof(double)); //You can divide the size of the array by the size of the type of the elements i the array and hence get the length in this example 32 bytes /8 bytes = 4 doubles in the array
    // in the case of a string a array of char's whose size is always 1, the size of the array i the number of elements
    // the trick doesn't work in functions only in the same scope as were the array was defigned sice when you pass a agument of a function your really passing in a pointer not the array object
    //sizeof is a replacment done by the compile time not a execution at runtime

    // You can inicialize array vaue during declaration 

    int arr[5] = {1, 2, 3, 4, 5}; // Nver go over the length or the compiler with tear you rhead off, if you add less the rest will be iniciallised to 0, this isn't done during normal declaration so to set all to 0 often people do:
    int arr2[5609] = {0}; //makes first 0 and then the rest automatically
    //during array delecaration it is also possible to set the mout of order to a specific index and get the into the right order
    int arr3[4] = {[1]=2, [2]=3, [0]=1, 4};
    for (int i = 0; i < sizeof(arr3)/sizeof(int); i++) {
        printf("%d\n", arr3[i]);
    }
    // you should think of this array declaration stuff like a cursor we start at 0 then jump to index 1 and place a 2 there, and so on then in the before last comand we go to index 0 and place a 1 there, then there is no jump command on the 4 so we just go to the enxt which is index 1 were the 2 was supposed to be and the 4 replaces it leaving a 4 in index 3
    // another cool thing about this way of declaration is you can elave of the length since it can find that out on its own
    int arr4[] = {1, 2, 3, 4};

    // There is a issue though since c doesn't track the length of arrays at run time, you can ask more values for arays past the length of the array
    printf("%d\n", arr[7]);
    printf("%d\n", arr[8]); // Outputs garbage values happening to be in memory


    /*
    Multi-Dimensional Arrays
    ----------------------------
    1.The first index determines the row and the second index determines the colum
    2. You do the declarations as shown bellow
    3. You do inplicit indexing in the same way
    */
    int multiArray[2][5] = {
        {1,2,3,4,5},
        {2,3,4,5,6}
    };

    // Make a 3x3 identity matrix
    int a[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};


    /*
    POINTERS AND ARRAYS
    -----------------------------
    1. A pointer to a array refers to a pointer tho the first element of the array
    2. int *p = &a[0] is sam as  int *p= a
    3. In fact when we plug arrays in as parameters we can use any of these syntax:
        void times2(int *a, int len)
        void times3(int a[], int len)
        void times4(int a[5], int len)
       we can treat it as a pointer which it is at the end of the dat or as a array lying to ourselves, we can even say array of x length, but its all syntactic sugar
       in the case we you pass in a number above 0 in the last case c doesn't even enforce it, but we can still take the pointer and do a[1] on it for some magical reason hopefully expplained later on
    4. Like all good langauges (sarcasm, specifically looking at you french) there is exceptions, when you pass a multi dimensional array in you needto pass in and its enforced every size of the array except for the first so that c knows how ot interpret the memory
       This is because in memory a multi dimensional array is R1C1 R1C2 R2C1 R2C2 ..., so to know how long ech of the row blocks are c needs to know how many colums there are but rows you just keep adding  another its fine, you can go over the length here c doesn't care
       

    */

    int array[] ={1, 2, 3, 4};
    int *p = &array[0];
    printf("%d\n", *p);



}

