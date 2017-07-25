#include <iostream>
using namespace std;

void Unknown(int *p, int num);
void HardToFollow(int *p, int q, int *num);

void Unknown(int *p, int num) {
  int *q; // create new pointer q

  q = &num; // set q to the address of num (trouble[0]); set q to the address of num (trouble[1] = 3)
  *p = *q + 2; // sets *p trouble[1] to 3; sets *p trouble[0] to 5
  num = 7; // this pretty much does nothing
}

void HardToFollow(int *p, int q, int *num) {
  // q = 1, *num = 3
  *p = q + *num; // sets trouble[1] to 4
  *num = q; // sets trouble[2] to 1
  num = p; // sets num pointer to p (trouble[1])
  p = &q; // sets p to the address of q (trouble[0] = 1)
  Unknown(num, *p); // calls Unknown with num -> trouble[1] = 4, and &trouble[0] = 1
}

int main() {
  // Create a pointer q that points to an int
  int *q;
  // Create an array of size 3 of ints
  int trouble[3];

  // set first element of trouble to 1
  trouble[0] = 1;
  // set q to point to the second element of trouble
  q = &trouble[1];
  // set the int pointed to by q to 2
  *q = 2;
  // set the third element of trouble to 3
  trouble[2] = 3;

  // q is a pointer to trouble[1] = 2, trouble[0] = 1, &trouble[2] is a pointer to trouble[2] = 3
  HardToFollow(q, trouble[0], &trouble[2]);
  // &trouble[0] still 1, *q is 3 (points to trouble[1])
  Unknown(&trouble[0], *q);

  // *q = 3, trouble[0] = 5, trouble[2] = 1
  cout << *q << " " << trouble[0] << " " << trouble[2] << endl;
}
