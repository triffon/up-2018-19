#include <iostream>
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

int main() {
  int a = 17, b = 3;
  cout << a << " = " << a / b << " * " <<
          b << " + " << a % b << endl;
  int die1 = 0, die2 = 0;
  cout << "Моля, хвърлете два зара: ";                                                      cin >> die1 >> die2;
  cout << "Имате ли дубъл? " << (die1 == die2) << endl;
  cout << "Нямаме дубъл и поне от заровете е четно число: " <<
    (die1 != die2 && (die1 % 2 == 0 || die2 % 2 == 0)) << endl;
}
