#include <stdio.h>
#include <string.h>

void counter(int *l, int *w, int *s, char *text);

int main(void) {
    char *text = "he Golden Rule—treat others the way you want to be treated—is perhaps the most universally understood idea across cultures, ages, and backgrounds because it relies on basic empathy, self-awareness, perspective-taking, and reciprocity, making it simple enough for even a child to grasp intuitively without formal education.";
    int letters = 0;
    int words = 0;
    int sentences = 0;
    counter(&letters, &words, &sentences, text);
    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index > 16) {
        printf("After Grade 16+\n");
    } else {
        printf("Grade %d\n", (int) index);
    }   
}

void counter(int *l, int *w, int *s, char *text) {
    for (int i = 0; i < strlen(text); i++) {
        if (((text[i] >= 'A') && (text[i] <= 'Z')) || ((text[i] >= 'a') && (text[i] <= 'z'))) {
            *l += 1;
        }
        if ((text[i] == '!') || (text[i] == '?') || (text[i] == '.') || (text[i] == ',')) {
            *w += 1;
            if (text[i] != ',') {
                *s += 1;
            }
        }
        if (i > 0) {
            if ((text[i] == ' ') && !((text[i - 1] == '!') || (text[i - 1] == '?') || (text[i - 1] == '.') || (text[i - 1] == ','))) {
            *w += 1;
            }
        }
    }
}