#include <iostream>

// Question answered from: http://pages.cs.wisc.edu/~hasti/cs368/CppTutorial/NOTES/CLASSES-INTRO.html

class IntList {
    public:
        IntList(); // constructor; initialize the list to be empty
        IntList(int n, int v); // constructor; initialize the list to n items of v
        void AddToEnd(int k); // add k to the end of the list
        int Length(); // return the length of the array
        void Print(ostream &output) const; // print the list to output

    private:
        int *Items; // Items will point to the dynamically allocated array
        int numItems; // number of items currently in the list
        int arraySize; // the current size of the array
};
