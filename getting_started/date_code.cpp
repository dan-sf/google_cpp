#include<iostream>
using namespace std;

string get_month(char month_code) {
    string months[] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return months[month_code - 'A'];
}

int get_date(char date_code) {
    return date_code - 'Q';
}

int get_year(char year_code) {
    return 1995 + year_code - 'A';
}

int main() {
    char code[] = "ARZM";
    cout << get_month(code[0]) << ", " << get_date(code[1]) << get_date(code[2]) << " " << get_year(code[3]) << endl;
}

