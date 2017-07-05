#include<iostream>
using namespace std;

int main() {
    int input_seconds;
    cout << "Number of seconds: "; cin >> input_seconds;

    cout << "Hours: " << input_seconds / 3600 << endl;
    input_seconds %= 3600;
    cout << "Minutes: " << input_seconds / 60 << endl;
    input_seconds %= 60;
    cout << "Seconds: " << input_seconds << endl;
}

