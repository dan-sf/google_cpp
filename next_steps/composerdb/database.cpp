#include <iostream>
#include <algorithm>
using namespace std;

#include "database.h"

Database::Database() {
    next_slot_ = 0;
}

Database::~Database() {
}

Composer& Database::AddComposer(string in_first_name, string in_last_name,
                        string in_genre, int in_yob, string in_fact) {
    Composer composer;

    composer.set_first_name(in_first_name);
    composer.set_last_name(in_last_name);
    composer.set_composer_yob(in_yob);
    composer.set_composer_genre(in_genre);
    composer.set_fact(in_fact);

    int current_slot = next_slot_;
    composers_[next_slot_++] = composer;

    return composers_[current_slot];
}

Composer& Database::GetComposer(string in_last_name) {
    for (int i = 0; i < next_slot_; i++)
        if (composers_[i].last_name() == in_last_name)
            return composers_[i];
    return composers_[0];
}

void Database::DisplayAll() {
    for (int i = 0; i < next_slot_; i++)
        composers_[i].Display();
}

static bool sortFunction(Composer a, Composer b) {
    return a.ranking() > b.ranking();
}

void Database::DisplayByRank() {
    Composer comp_sort[kMaxComposers];
    for (int i = 0; i < next_slot_; i++)
        comp_sort[i] = composers_[i];
    sort(comp_sort, (comp_sort + next_slot_), sortFunction);
    for (int i = 0; i < next_slot_; i++)
        comp_sort[i].Display();
}

