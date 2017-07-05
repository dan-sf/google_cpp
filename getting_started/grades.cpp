#include <iostream>
using namespace std;

int main() {
    float a1, a2, a3, a4;
    float mid, fin, sec;
    cout << "Enter the score for the first assignment: "; cin >> a1;
    cout << "Enter the score for the second assignment: "; cin >> a2;
    cout << "Enter the score for the third assignment: "; cin >> a3;
    cout << "Enter the score for the fourth assignment: "; cin >> a4;
    cout << "Enter the score for the midterm: "; cin >> mid;
    cout << "Enter the score for the final: "; cin >> fin;
    cout << "Enter the score for the section grade: "; cin >> sec;

    float grade = ((a1+a2+a3+a4)/4 * 0.4) + (mid*0.15) + (fin*0.35) + (sec*0.1);
    cout << "The final grade is: " << grade << endl;
}

