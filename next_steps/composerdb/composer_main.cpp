#include <iostream>
using namespace std;

#include "database.h"

void add_composer(Database& db) {
    string in_first_name;
    string in_last_name;
    string in_genre;
    int in_yob;
    string in_fact;

    cout << "Enter composer info:\n";
    cout << "First name: "; cin >> in_first_name;
    cout << "Last name: "; cin >> in_last_name;
    cout << "Genre: "; cin >> in_genre;
    cout << "YOB: "; cin >> in_yob;
    cout << "Fact: "; cin >> in_fact;

    db.AddComposer(in_first_name, in_last_name, in_genre, in_yob, in_fact);
}

void get_composer_info(Database& db) {
    string last_name;
    cout << "Last name of composer: "; cin >> last_name;
    db.GetComposer(last_name).Display();
}

void promote_demote_composer(Database& db) {
    Composer *composer;
    string last_name;
    int promotion;
    cout << "Last name of composer you'd like to promote or demote: "; cin >> last_name;
    composer = &db.GetComposer(last_name);
    composer->Display();
    cout << "Promote/Demote by (positive for promote, negative for demote): "; cin >> promotion;
    (promotion > 0) ? composer->Promote(promotion) : composer->Demote(-1*promotion);
    composer->Display();
}

void view_composer_all(Database& db) {
    db.DisplayAll();
}

void view_composer_by_rank(Database& db) {
    db.DisplayByRank();
}

int main() {
    Database db;
    int selection;
    bool exit = false;
    while(!exit) {
        cout << "\nComposer Database\n";
        cout << "---------------------------------------------\n";
        cout << "1) Add a new composer\n";
        cout << "2) Retrieve a composer's data\n";
        cout << "3) Promote/demote a composer's rank\n";
        cout << "4) List all composers\n";
        cout << "5) List all composers by rank\n";
        cout << "0) Quit\n";
        cout << "\nSelection: "; cin >> selection;

        switch(selection) {
            case 1:
                add_composer(db);
                break;
            case 2:
                get_composer_info(db);
                break;
            case 3:
                promote_demote_composer(db);
                break;
            case 4:
                view_composer_all(db);
                break;
            case 5:
                view_composer_by_rank(db);
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << "Error: Invalid input, try again\n";
        }
    }
}

