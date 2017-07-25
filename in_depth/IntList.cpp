#include <iostream>
using namespace std;

// Question answered from: http://pages.cs.wisc.edu/~hasti/cs368/CppTutorial/NOTES/CLASSES-INTRO.html

#include "IntList.h"

static int SIZE = 2; // initial size of the array (small value for testing)

IntList::IntList(): Items(new int[SIZE]), numItems(0), arraySize(SIZE) {
}

IntList::IntList(int n, int v): Items(new int[SIZE]), numItems(0), arraySize(SIZE) {
    for (int i = 0; i < n; i++)
        this->AddToEnd(v);
}

void IntList::AddToEnd(int k) {
    if (numItems < SIZE)
        Items[numItems++] = k;
    else {
        SIZE *= 2;
        int *new_items = new int[SIZE];
        for (int i = 0; i < numItems; i++)
            new_items[i] = Items[i];
        new_items[numItems++] = k;
        int *p = Items;
        Items = new_items;
        free(p);
    }
}

int IntList::Length() {
    return numItems;
}

void IntList::Print(ostream &output) const {
    for (int i = 0; i < numItems; i++)
        output << Items[i] << endl;
}

