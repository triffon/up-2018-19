#include <iostream>
using namespace std;

long fact(long n) {
  if (n == 0)
    return 1;
  return n * fact(n - 1);
}

int gcd(int a, int b) {
  if (a == b)
    return a;
  if (a > b)
    return gcd(a - b, b);
  return gcd(a, b - a);
}

double power(double x, int n) {
  if (n == 0)
    return 1;
  if (n > 0)
    return x * power(x, n - 1);
  return 1 / power(x, -n);
}

const int MAX_FIB = 100;

unsigned long Fib[MAX_FIB] = {0};

unsigned long remember(int n, unsigned long x) {
  Fib[n] = x;
  return x;
}

unsigned long fib(int n) {
  if (n <= 1)
    return n;
  if (Fib[n] != 0)
    return Fib[n];
  return remember(n, fib(n - 2) + fib(n - 1));
}


void testrecursion() {
  cout << fact(4) << endl;
  cout << gcd(12, 20) << endl;
  cout << power(2, -3) << endl;
  for(int i = 0; i < 43; i++)
    cout << fib(i) << endl;
}

bool isdigit(char c) {
  return '0' <= c && c <= '9';
}

bool isop(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=';
}

int calculate(int arg1, char op, int arg2) {
  switch(op) {
  case '+': return arg1 + arg2;
  case '-': return arg1 - arg2;
  case '*': return arg1 * arg2;
  case '/': return arg1 / arg2;
  case '%': return arg1 % arg2;
  }
  return 0;
}

int todigit(char c) {
  return c - '0';
}

/*
   <израз> ::= <цифра> | (<израз><операция><израз>)
   функцията ще пресмята израза започващ от s
   и ще премества s след края на израза
*/

int calculate_expr(char const*& s) {
  cout << "Смятаме израза " << s << endl;
  if (isdigit(*s))
    // пресмятаме цифрата и преместваме s след нея
    return todigit(*s++);
  // пропускаме скобата
  s++;
  int left = calculate_expr(s);
  // s сочи точно към операцията
  char op = *s++;
  // s сочи точно в началото на десния израз
  int right = calculate_expr(s);
  // s сочи към затварящата скоба, пропускаме я
  s++;
  // s вече сочи след края на израза, който обработваме
  int result = calculate(left, op, right);
  cout << "Връщаме резултат " << result << endl;
  return result;
}

const int MAXEXPR = 101;

void testexpression() {
  char expr[MAXEXPR] = "";
  cout << "Въведете израз: ";
  cin.getline(expr, MAXEXPR);
  char const *s = expr;
  cout << "Резултатът е: " << calculate_expr(s) << endl;
  
}

int main() {
  // testrecursion();
  testexpression();
}
