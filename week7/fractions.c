#include <stdio.h>

int addFraction(int a, int b, int c, int d);
int subFraction(int a, int b, int c, int d);
int mulFraction(int a, int b, int c, int d);
int gcd(int a, int b);

int main() {

    addFraction(9, 9, 4, 12);
    return 0;
}

int addFraction(int a, int b, int c, int d) {
    int numerator = (a * d) + (b * c);
    int denominator = b * d;
    int greatest = gcd(numerator, denominator);
    printf("numerator: %d denominator: %d\n", numerator, denominator);
    if(greatest == 0) {
        return 1;
    } else {
        numerator /= greatest;
        denominator /= greatest;
    }
    printf("numerator: %d denominator: %d", numerator, denominator);
    return 0;
}

int gcd(int a, int b) {
    int gcd = 0;
    if(a < b) {
        for(int i = 1; i <= a; i++) {
            if(a % i == 0 && b % i == 0) {
                gcd = i;
            }
        }
    } else if (a > b) {
        for(int i = 1; i <= b; ++i) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    } else if(a == b) {
        return a;
    }
    printf("greatest common divisor is: %d", gcd);
    return gcd;
}