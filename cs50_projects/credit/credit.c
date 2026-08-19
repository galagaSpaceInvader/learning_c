#include <stdio.h>
#include <stdbool.h>

long long nToThePowerOfTen (int n);

bool luhns_alg (long long card, int length);

int main(void) {
    long long creditCardNumber = 2221000000000009;
    long long division;
    int i = 1;
    do {
        division = creditCardNumber / nToThePowerOfTen(i);
        i++;
    } while (division > 0);
    int length = i-1;
    int first_num = (int) (creditCardNumber/nToThePowerOfTen(length-1));
    int second_num = (int) (creditCardNumber/nToThePowerOfTen(length-2)) - 10 * first_num;
    int fallThrough = 0;
    if (luhns_alg(creditCardNumber, length)) {
        switch (length) {
            case 15:
                if ((first_num == 3 && second_num == 4) || (first_num == 3 && second_num == 7)) {
                    printf("American Express\n");
                    return 0;
                } else {
                    fallThrough = 1;
                }
            case 16:
                if (fallThrough == 0) {
                    if (first_num == 4) {
                        ; // Letting all 16 number length visa cards fall through to the next case
                    } else if (first_num == 5 && (second_num >= 1 && second_num <= 5)) {
                        printf("Master Card\n");
                        return 0;
                    }
                }
            case 13:
                if (fallThrough == 0 && first_num == 4) {
                    printf("Visa\n");
                    return 0;
                }
        }
    }
    printf("INVALID\n");
    return 0;
}


long long nToThePowerOfTen (int n) {
    long long resault = 1;
    for (int i = 0; i < n; i++) {
        resault *= 10;
    }
    return resault;
}

bool luhns_alg (long long card, int length) {
    int noProduct = 0;
    int product = 0;
    long long total_sum = 0;
    int n;
    for (int i = 0; i < length; i++) {
        n =  (int) (((card % nToThePowerOfTen(i + 1)) - total_sum) / nToThePowerOfTen(i));
        total_sum += n * nToThePowerOfTen(i);
        if ((i+1) % 2 == 1) {
            noProduct += n;
        } else {
            if (2*n >= 10) {
                product += ((2*n) % 10);
                product += ((((2*n) % 100) - ((2*n) % 10)) / 10);
            } else {
                product += 2*n;
            }
        }
    } //we switch what total sum does no instead of tracking all the values fo digits before hand now it stores product + no prudct sums
    total_sum = noProduct + product;
    if (total_sum % 10 == 0) {
        return true;
    } else {
        return false;
    }
    
}