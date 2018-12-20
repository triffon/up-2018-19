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

int main() {
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
