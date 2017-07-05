#include<iostream>
using namespace std;

int rotate(int num) {
    int num_list[3];
    num_list[0] = num % 10; num /= 10;
    num_list[1] = num % 10; num /= 10;
    num_list[2] = num % 10; num /= 10;
    return num_list[1] * 100 + num_list[0] * 10 + num_list[2];
}

int normalize(int num) {
    int tmp;
    while (num != 9 && num % 2 != 0 && num >= 0 && num < 20) {
        tmp = num - 11;
        if (tmp >= 0 && tmp < 20) { num = tmp; continue; }
        tmp = num + 11;
        if (tmp >= 0 && tmp < 20) num = tmp;
    }
    return num;
}

int main() {
    int a = 123;
    int b = rotate(a);
    int c = rotate(b);

    int rem_a = a % 11;
    int rem_b = b % 11;
    int rem_c = c % 11;

    int x, y, z;
    x = normalize(rem_a + rem_b);
    y = normalize(rem_b + rem_c);
    z = normalize(rem_c + rem_a);

    x /= 2;
    y /= 2;
    z /= 2;

    printf("x: %d, y: %d, z: %d\n",x,y,z);
}

