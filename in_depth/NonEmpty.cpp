#include <iostream>
#include <string>
#include <vector>

// Question answered from: http://pages.cs.wisc.edu/~hasti/cs368/CppTutorial/NOTES/CLASSES-INTRO.html

using namespace std;

vector<string> NonEmpty(vector<string> v) {
    vector<string> output(v.size());
    int count = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i] != "")
            output[count++] = v[i];
    output.resize(count);
    return output;
}

int main() {
    vector<string> s;
    s.push_back("hello");
    s.push_back("");
    s.push_back("bye");
    s.push_back("");
    s.push_back("");
    s.push_back("!");

    vector<string> ns = NonEmpty(s);
    for (int i = 0; i < ns.size(); i++)
        cout << ns[i] << endl;
}
