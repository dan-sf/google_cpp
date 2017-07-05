#include <iostream>
using namespace std;

int main() {
    int input_var = 0;

    srand(time(NULL));
    int rand_val = rand() % 100 + 1;

    do {
        cout << "Enter a number between 1 and 100 (-1 = quit): ";
        // The following line accepts input from the keyboard into
        // variable input_var.
        // cin returns false if an input operation fails, that is, if
        // something other than an int (the type of input_var) is entered.
        if (!(cin >> input_var)) {
            cout << "You entered a non-numeric." << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            continue;
            // exit the do while loop
        }
        if (input_var != -1) {
            if (input_var == rand_val)
                cout << "You guessed the correct number! Yay!" << endl;
            else
                if (input_var > rand_val)
                    cout << "You guessed too high try again." << endl;
                else
                    cout << "You guessed too low try again." << endl;
        }
    } while (input_var != rand_val && input_var != -1);

    cout << "Exiting." << endl;
    return 0;
}

