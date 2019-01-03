#include <iostream>
using namespace std;

const int MAX = 10;
const int MAXC = 21;

int readStringArray(char sa[][MAXC]) {
  int n;
  cout << "n = ";
  cin >> n;
  char c = cin.get();
  for(int i = 0; i < n; i++) {
    // cin >> sa[i]; 
    cin.getline(sa[i], MAXC);
    /*
    if (!cin) {
      cout << "Грешка!\n";
      return i + 1;
      }*/
    cin.clear();
  }
  return n;
}

void printStringArray(char sa[][MAXC], int n) {
  for(int i = 0; i < n; i++)
    cout << "->" << sa[i] << "<-\n";
}

void printMatrix(int a[][MAX], int m, int n) {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++)
      cout << a[i][j] << '\t';
    cout << endl;
  }
}

void readMatrix(int a[][MAX], int& m, int& n) {
  cout << "m = ";cin >> m;
  cout << "n = ";cin >> n;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
      cout << "a[" << i << "][" << j << "] = ";
      cin >> a[i][j];
    }
}

void multiplyMatrices(int a[][MAX], int b[][MAX], int c[][MAX],
                      int m, int n, int k) {
  for(int i = 0; i < m; i++)
    for(int j = 0; j < k; j++) {
      c[i][j] = 0;
      for(int l = 0; l < n; l++)
        c[i][j] += a[i][l] * b[l][j];
    }
}

int* badpointer(int* p) {
  // !!! int y = x;
  // !!! return &x;
  // !!! return &y;
  return p;
}

int& badreference(int& x) {
  // !!! return x;
  int y = x;
  // !!! return y;
  return x;
}

int* badarray(int x, int b[]) {
  // !!! int a[6] = { 0, 1, x, 3, 4, 5 };
  // !!! return a;
  b[2] = x;
  return b + 1;
}

void testfunctions() {
  char sa[MAX][MAXC];
  int n = readStringArray(sa);
  printStringArray(sa, n);
  int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
  int m, k;
  readMatrix(a, m, n);
  readMatrix(b, n, k);
  multiplyMatrices(a, b, c, m, n, k);
  printMatrix(c, m, k);
}

void badfunctions() {
  // !!! int* p = badpointer(3);
  int x = 10;
  int* p = badpointer(&x);
  cout << *p << endl;
  // !! cout << badreference(3) << endl;
  badreference(x) = 20;
  cout << x << endl;
  int c[6] = { 0, 1, 2, 3, 4, 5 };
  p = badarray(x, c);
  cout << p[1] << ' ' << p[2] << endl;
}

char const* our_strchr(char const* s, int c) {
  while (*s && *s != c)
    s++;
  // *s == '\0' || *s == c
  if (*s != c)
    return nullptr;
  return s;
}

void teststringfunctions() {
  cout << our_strchr("Hello, world!", 'l') << endl;
  if (!our_strchr("Hello, world!", 'z'))
    cout << "z не се среща\n";
}

int main() {
  // testfunctions();
  // badfunctions();
  teststringfunctions();
}
