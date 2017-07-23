#include <stdio.h>

bool is_sum_of_ints(int num) {
    // Function to check if a given number is a sum of integers 1..n
    int i;
    for (i = 1; i*i + i <= num * 2; i++)
        if ((i*i + i) == (num * 2)) // Gauss's method for summing ranges of ints
            return true;
    return false;
}

int main() {
    // Print out the first 5 numbers that are perfect squares and are a sum of
    // a range of integers
    int count = 0;
    for (int i = 0; count < 5; i++) {
        if (is_sum_of_ints(i*i)) {
            count++;
            printf("%d: %d\n", count, i*i);
        }
    }
}

