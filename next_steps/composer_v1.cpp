#include <iostream>
#include <vector>
using namespace std;

struct composer {
    int rank;
    string name;
    void print() {
        cout << "Composer:\n\tName: " << name << "\n\tRank: " << rank << "\n";
    }
};

void add_composer(vector<composer> *c_list) {
    composer new_composer;
    string name;
    int rank;

    cout << "Please enter composer information:\n";
    cout << "\tName: "; cin >> name;
    cout << "\tRank: "; cin >> rank;

    new_composer.name = name;
    new_composer.rank = rank;

    c_list->push_back(new_composer);
}

void view_composer_rank(vector<composer> *c_list) {
    int rank;

    cout << "Please enter the composer rank you would like to view:\n";
    cout << "\tRank: "; cin >> rank;

    cout << "\nAll composers of rank " << rank << endl << endl;
    for (int i = 0; i < c_list->size(); i++) {
        if ((*c_list)[i].rank == rank)
            (*c_list)[i].print();
    }
}

void view_composer_all(vector<composer> *c_list) {
    cout << "\nAll composers:" << endl << endl;
    for (int i = 0; i < c_list->size(); i++) {
        (*c_list)[i].print();
    }
}

int main() {
    vector<composer> composer_list; 
    int selection;
    bool exit = false;
    while(!exit) {
        cout << "Select an option:\n";
        cout << "\t1. Add a new composer\n";
        cout << "\t2. View composers of a specific rank\n";
        cout << "\t3. View all composers\n";
        cout << "\t4. Exit\n";
        cout << "Selection: "; cin >> selection;

        switch(selection) {
            case 1:
                add_composer(&composer_list);
                break;
            case 2:
                view_composer_rank(&composer_list);
                break;
            case 3:
                view_composer_all(&composer_list);
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Error: Invalid input, try again\n";
        }
    }
}

