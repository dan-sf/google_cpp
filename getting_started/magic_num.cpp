#include<iostream>
using namespace std;

int rev(int num) {
    int num_list[3];
    num_list[0] = num % 10; num /= 10;
    num_list[1] = num % 10; num /= 10;
    num_list[2] = num % 10; num /= 10;
    return num_list[0] * 100 + num_list[1] * 10 + num_list[2];
}

int main() {
    int input_num, rev_num, sub_num, sub_num_rev;

    cout << "Input 3 digit number with first digit greater than the last: "; cin >> input_num;
    rev_num = rev(input_num);
    sub_num = input_num - rev_num;
    sub_num_rev = rev(sub_num);

    cout << "Output number: " << sub_num_rev + sub_num << endl;
}

