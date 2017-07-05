#include <fstream>
#include <iostream>
using namespace std;

struct person_info {
    string first_name;
    string last_name;
    string age;
};

void write_to_file(ofstream& File, string first_name, string last_name, string age) {
    File << "First name: " << first_name << endl;
    File << "Last name: " << last_name << endl;
    File << "Age: " << age << endl;
}

void get_data(person_info* person) {
    // Fill out the person struct
    cout << "Enter First Name: "; cin >> person->first_name;
    cout << "Enter Last Name: "; cin >> person->last_name;
    cout << "Enter Age: "; cin >> person->age;
}

int main() {
    bool cont = false;
    string user_cont;
    person_info person;
    string file_name;

    cout << endl;
    cout << "Enter the name of the file you would like to write to: "; cin >> file_name;
    cout << endl;
    ofstream People(file_name, ios::out);

    do {
        get_data(&person);
        write_to_file(People, person.first_name, person.last_name, person.age);
        cout << "Would you like to enter another person (y/n): "; cin >> user_cont;
        cont = true ? user_cont == "y" : false;
    } while (cont);

    People.close();

    cout << endl;
    cout << "File output:" << endl;
    cout << endl;

    string line;
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << '\n';
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }

    return 0;
}

