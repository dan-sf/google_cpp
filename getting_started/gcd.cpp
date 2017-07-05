#include <iostream>
using namespace std;

int gcd(int a, int b) {
    a = a < 0 ? a*-1 : a;
    b = b < 0 ? b*-1 : b;
    int smaller = a >= b ? b : a;
    printf("this is smaller: %d\n", smaller);

    while (a % smaller != 0 || b % smaller != 0) {
        smaller--;
    }
    return smaller;
}

int main() {
    printf("This is the gcd: %d\n", gcd(-4, 14));
}

