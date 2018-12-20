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

void testPointerArithmetic() {
  int a[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
  int* p = &a[2];
  cout << "sizeof(a) = " << sizeof(a) << endl;
  cout << "sizeof(a[1]) = " << sizeof(a[1]) << endl;
  cout << "sizeof(*a) = " << sizeof(*a) << endl; // <-> a[0]
  cout << "sizeof(p) = " << sizeof(p) << endl;
  cout << "sizeof(*p) = " << sizeof(*p) << endl;
  cout << "p = " << p << endl;
  cout << "p + 2 = " << p + 2 << endl;
  cout << "*p = " << *p << endl;  // p == &a[2]  <-> *p == a[2]
  cout << "(*p) + 2 = " << *p + 2 << endl; // a[2] + 2
  cout << "*(p + 2) = " << *(p + 2) << endl; // a[2 + 2]
  cout << 2[a] << ' ' << 4[a] << endl;
}

void print(char const* p) {
  while (*p) {
    cout << *p++;
    // !!! p++;
  }
}

int my_strlen(char const* p) {
  char const* start = p;
  while (*p) {
    p++;
  }
  return p - start;
}

char const* greeting(bool leaving) {
  if (leaving)
    return "Goodbye!";
  else
    return "Hello!";
}

void testCharPointers() {
  char s[] = "Hello, world!";
  print(s);
  cout << my_strlen(s) << endl;
  char const USD = '$';
  char const HASH = '#';
  char const* q = &USD;
  cout << *q << endl;
  // !!! char* p = &USD; // <-> char* p = q;
  q = &HASH;
  cout << *q << endl;
  char const* const r = &HASH;
  // !!! *r = '%';
  // !!! r = &USD;
  cout << *r << endl;
  const int N = 10;
  /*
!!!
  int *pi = (int*)&N; // (int const*)
  *pi = 20;
  cout << N << endl;
  cout << *pi << endl;
!!!
  */
  // !!!!! char *p = "Hello, world!"; // <-> char const*
  //  !!! p[3] = 'x';
  // !!! cout << p << endl;
  q = "Hello, world!";
  // !!! q[2] = 'x';
  cout << q << endl;
  // !!! char *p =  greeting(false);
  // !!! p[1] = 'a';
  q = greeting(false); // !!!
  cout << q << endl;
  print(s);
  my_strlen(s);
  cout << q << endl;  
}

void testVoidPointers() {
  int x = 3;
  void* q = &x;
  double y = 12;
  q = &y;
  int* s = (int*)q; // !!!
  cout << *s << endl;
  // !!! cout << *q << endl;
}

void testReferences() {
  int x = 3, // цяло число
    *p = &x, // указател към цяло число
    &q = x, // препратка към цяло число
    b[5] = { 1, 2, 3, 4, 5 }; // масив от цели числа
  q += 10;
  cout << x << endl;
  (*p) += 10;
  cout << x << endl;
  int& r = b[2];
  r += 10;
  cout << b[2] << endl;
}

int main() {
  cout << "---------------------\n";
  // testPointers();
  // testPointerArithmetic();
  // testCharPointers();
  // testVoidPointers();
  testReferences();
  cout << "---------------------\n";
  return 0;
}
