#include <iostream>
using namespace std;

// int *imfeelinglucky;

void testPointers() {
  int x = 5, y = 7;
  int *p = &x, z = 10, a[10], *q = &y;
  cout << p << endl;
  cout << *p << endl;
  cout << q << endl;
  cout << *q << endl;
  //  cout << *imfeelinglucky << endl;
  int *pd = nullptr;
  if (pd != nullptr)
    cout << *pd << endl;
  int **qq = &q;
  cout << qq << endl;
  cout << *qq << endl;
  cout << **qq << endl;
}

int main() {
  cout << "---------------------\n";
  testPointers();
  cout << "---------------------\n";
  return 0;
}
