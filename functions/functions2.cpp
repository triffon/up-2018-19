#include <iostream>
using namespace std;


int f(int x) {
  cout << "x = " << x << endl;
  static int N = 5;
  x += N;
  N--;
  return x;
}

void cbvExample() {
  int y = 2;
  int z = f(y);
  cout << "функцията върна: " << z << endl;
  cout << "y = " << y << endl;
  z = f(y);
  cout << "функцията върна: " << z << endl;
  cout << "y = " << y << endl;  
  z = f(y);
  cout << "функцията върна: " << z << endl;
  cout << "y = " << y << endl;  
  // N = 5;
  z = f(y);
  cout << "функцията върна: " << z << endl;
  cout << "y = " << y << endl;
}

int add5(int& x) {
  x += 5;
  return x;
}

void cbrExample() {
  int y = 2;
  int z = add5(y);
  // int z = add5(2 * y);
  cout << "функцията върна: " << z << endl;
  cout << "y = " << y << endl;
}

void my_swap(int& x, int& y) {
  cout << "Ще разменяме int!\n";
  int tmp = x;
  x = y;
  y = tmp;
}

void my_swap(short& x, short& y) {
  cout << "Ще разменяме short!\n";
  short tmp = x;
  x = y;
  y = tmp;
}

void my_swap(double& x, double& y) {
  cout << "Ще разменяме double!\n";
  double tmp = x;
  x = y;
  y = tmp;
}


void swapTest() {
  int a = 3, b = 5;
  my_swap(a, b);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  double c = 3.5, d = 5.8;
  my_swap(c, d);
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;

  // !!! unsigned e = 1, f = 2;
  // !!! my_swap(e, f);
}

const int MAX = 5;

// void printArray(int a[MAX], int n) {
void printArray(int a[], int n) {
//void printArray(int* a, int n) {
  for(int i = 0; i < n; i++)
// !!!    cout << a[i]++ << ' ';
    cout << a[i] << ' ';
  cout << endl;
}

int readArray(int a[]) {
  int n;
  cout << "n = ";cin >> n;
  for(int i = 0; i < n; i++) {
    cout << "a[" << i << "] = ";
    cin >> a[i];
  }
  return n;
}

bool search(int a[], int n, int x) {
  int i = 0;
  while (i < n && a[i] != x)
    i++;
  return i < n;
}

//void findMinMax(int a[], int n, int result[]) {
void findMinMax(int a[], int n, int& min, int& max) {
  // int min = a[0], max = a[0];
  min = max = a[0];
  for(int i = 1; i < n; i++) {
    if (a[i] < min)
      min = a[i];
    if (a[i] > max)
      max = a[i];
  }
  // result[0] = min;
  // result[1] = max;
}

void arrayFunctions() {
  int b[MAX] = { 1, 2, 3, 4, 5 };
  int c[2 * MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  printArray(b, 5);
  printArray(b, 5);
  printArray(c, 10);
  int n = readArray(b);
  printArray(b, n);
  cout << (search(b, n, 2) ? "има 2" : "няма 2") << endl; 
  int result[2];
  int min, max;
  //  findMinMax(b, n, result);
  findMinMax(b, n, min, max);
  cout << "min = " << min << endl;
  cout << "max = " << max << endl;
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

void print5Tensor(int a[][MAX][MAX][MAX][MAX], int dimensions[]) {
  int i[5];
  for(i[0] = 0; i[0] < dimensions[0]; i[0]++)
    for(i[1] = 0; i[1] < dimensions[1]; i[1]++)
      for(i[2] = 0; i[2] < dimensions[2]; i[2]++)
        for(i[3] = 0; i[3] < dimensions[3]; i[3]++)
          for(i[4] = 0; i[4] < dimensions[4]; i[4]++)
            cout << "a[" << i[0] << "]["
                 << i[1] << "]["
                 << i[2] << "]["
                 << i[3] << "]["
                 << i[4] << "] = " << a[i[0]][i[1]][i[2]][i[3]][i[4]] << endl;   
}

void matricesFunctions() {
  int b[MAX][MAX];
  int rows, columns;
  readMatrix(b, rows, columns);
  printMatrix(b, rows, columns);

  int c[MAX][MAX][MAX][MAX][MAX] = { 1, 2, 3, 4, 5, 6 };
  int dimensions[] = { 2, 3, 4, 2, 3 };
  print5Tensor(c, dimensions);
  
}

int main2() {
  cout << "-------------------------" << endl;
//  cbvExample();
//  cbrExample();
//  swapTest();
//  arrayFunctions();
  matricesFunctions();
  cout << "-------------------------" << endl;
  return 0;
}
