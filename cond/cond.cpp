#include <iostream>
using namespace std;
int ineq() {
  double a, b;
  cin >> a >> b;
  if (b >= 0)
    if (a > 0)
      // b >= 0 && a > 0
      cout << 1;
    else
      // b >= 0 && a <= 0
      cout << 4;
  else
    // b < 0
    if (a >= 0)
      // b < 0 && a >= 0
      cout << 3;
    else
      // b < 0 && a < 0
      cout << 2;
  return 0;
}

int incr() {
  int a, b, c;
  cin >> a >> b >> c;
  /*
  if (a < b && b < c)
    cout << "Числата образуват растяща редица\n";
  else
    cout << "Числата НЕ образуват растяща редица\n";
  */
  cout << "Числата ";
  //  if (!(a < b && b < c))
  if (a >= b || b >= c)
    cout << "НЕ ";
  cout << "образуват растяща редица\n";
  return 0;
}

int findmin() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << "Най-малкото число е: ";
  if (a < b && a < c) {
    cout << a;
  } else
    // a >= b || a >= c
    // сигурни сме, че най-малкото число е едно от b и c
    if (b < c)
      cout << b;
    else
      // b >= c
      cout << c;
  cout << endl;
  return 0;
}

int sort3() {
  int a, b, c;
  cin >> a >> b >> c;
  // boring:
  /*
  if (a <= b && b <= c)
    cout << a << ' ' << b << ' ' << c << endl;
  else
    if (b <= a && a <= c)
      cout << b << ' ' << a << ' ' << c << endl;
    else ...
  */
  // magic happens here
  // размяна на a и b:
  if (b < a) {
    int tmp = b;
    b = a;
    a = tmp;
  }
  // a <= b
  if (c < b) {
    int tmp = b;
    b = c;
    c = tmp;
  }
  // b <= c && (a <= c || a <= b)
  if (b < a) {
    int tmp = b;
    b = a;
    a = tmp;
  }
  // a <= b && b <= c
  cout << a << ' ' << b << ' ' << c << endl;
  return 0;
}

int switchtest() {
  int x;
  cout << "x = ";
  cin >> x;
  switch (x) {
  case 1 : x++;     break;
  case 2 : x += 2;  break;
  default : x += 5;
  }
  cout << "x = " << x << endl;
  return 0;
}
  
int calculator() {
  cout << "Въведете израз: ";
  int a, b, result;
  char op;
  cin >> a >> op >> b;
  switch (op) {
  case '+' : result = a + b; break;
  case '-' : result = a - b; break;
  case '*' : result = a * b; break;
  case '/' : result = a / b; break;
  case '%' : result = a % b; break;
  default : result = 0;
  }
  cout << a << ' ' << op << ' ' << b << " = " << result << endl;
  return 0;
}

int main() {
  char letter;
  cin >> letter;
  if ('a' > letter || letter > 'z')
    cout << "'" << letter << "' не е малка латинска буква!\n";
  else
    switch (letter) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':cout << "Буквата '" << letter << "' е гласна\n"; break;
    default :cout << "Буквата '" << letter << "' е съгласна\n";
    }
  return 0;
}
