#include <stdio.h>

struct worker {
    char *name;
    int sallery;
    float efficiency;
}; // <- Don't forget this little guy
// This guy is now a type important to note the type isnt "worker" but "struct worker"

void setwage(struct worker *w, int new_wage);

int main(void) {
    // Structs are user defignable types that hold multiple variables in one, they are good for organising code and mkaing it so you have to pass less variables into functions
    struct worker w1; // creates a variable w1 of type struct worker, not we can set some variables
    w1.name = "Bob";
    w1.sallery = 200;
    w1.efficiency = 0.8f;

    printf("The variable w1 holds data about a worker called %s, he makes $%d a week  and his working efficency is(the amount fo time he sends working of the time he is at work)%f.\n",w1.name, w1.sallery, w1.efficiency);

    // you can defign these guys a little like arrays too by going
    struct worker w2 = {"Gary", 200, 0.9f};
    // or to make it independed of order
    struct worker w3 = {.name="Eyown", .sallery=300, .efficiency=0.9f};

    // For passing these guys into functions you can either pass the struct or pass a pointer to them
    // Since structs are usually heavy to copy takign up a lot of memory usually a pointer is passed through
    setwage(&w2, 310);
    printf("%s's sallery is:%d\n", w2.name, w2.sallery); 
    // to copy these guys all you need to do is set them equal to eahc other
}

void setwage(struct worker *w, int new_wage) {
    //we can't use . notation directly on w sinc its a pointer, so we can derefrence it (making use its the first operation done using these), then apply it
    (*w).sallery = new_wage;
    //this is kind of ugly using non native techniques so better to do
    w -> sallery = new_wage;

}