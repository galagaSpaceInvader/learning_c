#include <stdio.h>
#include <string.h>

int pointCounter(const char *word);

int main(void) {
    char *player1 = "Apple!";
    char *player2 = "Apple!";

    int p1Points = pointCounter(player1);
    int p2Points = pointCounter(player2);
    printf("%d\n",p1Points);
    printf("%d\n",p2Points);

    if (p1Points == p2Points) {
        printf("Its a tie!\n");
    } else if (p1Points > p2Points) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
}

int pointCounter(const char *word) { // makes it so we can't edit the word through the pointer accidentally causing undefigned behaviour
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char c;
    int totalPoints = 0;
    for (int i = 0; i < strlen(word); i++) {
        c = word[i]; //if its capital + 32
        if ((c >= 65) && (c <= 90)) {
            totalPoints += points[c-65];
        } else if ((c >= 97) && (c <= 122)) {
            totalPoints += points[c-97];
        }
    }
    return totalPoints;
}