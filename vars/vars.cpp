#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int vars() {
  char c = 'F', c2 = 'X';
  int a = -200, b;
  b = a + 5;
  cout << "b = " << b << endl;
  cout << c << ' ' << c2 << ' ' << a << ' ' << b << endl;
  cout << "Моля, въведете a и b, а после и d: ";
  cin >> a >> b;
  int d;
  cin >> d;
  cout << c << ' ' << c2 << ' ' << a << ' ' << b << ' ' << d << '\n';
  // !!! const int N;
  // !!! cout << d * "20";
  return 0;
}

int bools() {
  bool isCorrect = false, willFix = true;
  bool allGood = isCorrect || willFix; // (!isCorrect -> willFix)
  cout << allGood << endl;
  return 0;
}

int ints() {
  int a = 17, b = 3;
  cout << a << " = " << a / b << " * " <<
          b << " + " << a % b << endl;
  int die1 = 0, die2 = 0;
  cout << "Моля, хвърлете два зара: ";                                                      cin >> die1 >> die2;
  cout << "Имате ли дубъл? " << (die1 == die2) << endl;
  cout << "Нямаме дубъл и поне от заровете е четно число: " <<
    (die1 != die2 && (die1 % 2 == 0 || die2 % 2 == 0)) << endl;
  return 0;
}

int floats() {
  long double f1 = 1.25;
  f1 -= 0.25;
  f1 -= 0.25;
  f1 -= 0.25;
  f1 -= 0.25;
  f1 -= 0.25;
  cout << "f1 = " << f1 << endl;

  long double f2 = 1.2;
  f2 -= 0.4;
  f2 -= 0.4;
  f2 -= 0.4;

  cout << "f2 = " << f2 << endl;

  (((cout << "f1 == f2? ") << (f1 == f2)) << endl);
  const double EPS = 1e-5; // 0.00001
  cout << "f1 ≈ f2? " << (fabs(f1 - f2) < EPS) << endl;
  cout << "f1 ≈/≈ f2? " << (fabs(f1 - f2) >= EPS) << endl;
  return 0;
}

int main() {
  short s = 15;
  double d = 2e-3;
  cout << "s + d = " << s + d << endl;
  cout << true + 'A' - 15 + (cout << M_PI << endl, M_PI) << endl;
  char c = 'H';
  cout << (c - 'A') << endl;
  char digit = '5';
  cout << digit + 15 << endl;
  cout << (digit - '0') + 15 << endl;

  s = 1.53; // !!!
  cout << "s = " << s << endl;
  c = 65.53; // !!!
  cout << "c = " << c << endl;
  cout << "#c = " << (short)c << endl;
  int ccode = c;
  cout << "#c = " << ccode << endl;
  bool b = M_PI; // !!!
  unsigned u = -5;
  cout << "u = " << u << endl;
  cout << "π ≈ " << (int)M_PI << endl;
  int x = floor(5.8);
  int y = +8;
  cout << "y = " << y << endl;
  int z = +-+y;
  cout << "z = " << z << endl;
  2;
  (sqrt(5) + M_PI);
  cout << pow(8, 1./3) << endl;
  cout << x + (y = 3) << endl;
  cout << "y = " << y << endl;
  cout << setprecision(10) << M_PI << endl;
  cout << "y = " << ++y << endl; // (y = y + 1)
  cout << "y = " << y << endl;
  cout << "y = " << y++ << endl;
  cout << "y = " << y << endl;
  ++y += 5;
  cout << "y = " << y << endl;
  {
    char y = 'x';
    cout << "y = " << y << endl;
    double cout = 5.3; // !!!
    // !!! cout << "y = " << y << endl;
  }
  cout << "y = " << y << endl;
  return 0;
}
