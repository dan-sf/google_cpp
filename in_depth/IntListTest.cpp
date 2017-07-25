#include <iostream>
using namespace std;

// Question answered from: http://pages.cs.wisc.edu/~hasti/cs368/CppTutorial/NOTES/CLASSES-INTRO.html

#include "IntList.h"

int main() {
    IntList il;
    for (int i = 0; i < 10; i++)
        il.AddToEnd(i + 30);
    il.Print(cout);
    cout << "Length: " << il.Length() << endl;

    IntList il2(5,6);
    for (int i = 0; i < 3; i++)
        il2.AddToEnd(i + 30);
    il2.Print(cout);
    cout << "Length: " << il2.Length() << endl;
}

