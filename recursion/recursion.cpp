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


void printArray(int a[], int n) {
  for(int i = 0; i < n; i++)
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

const int MAX = 100;

int sumArray(int a[], int n) {
  if (n == 0)
    return 0;
  // return sumArray(a, n - 1) + a[n - 1];
  return a[0] + sumArray(a + 1, n - 1);
}

bool search(int a[], int n, int x) {
  return n > 0 && (a[0] == x || search(a + 1, n - 1, x));
  
  if (a[0] == x)
    return true;
  if (n == 0)
    return false;
  // a[0] != x
  // n != 0
  // if (p) return true; else return false; <-> return p;
  /*
  if (search(a + 1, n - 1, x))
    return true;
  else
    return false;
  */
  return search(a + 1, n - 1, x);
}

bool sorted(int a[], int n) {
  return n <= 1 || (a[0] <= a[1] && sorted(a + 1, n - 1));
    
  if (n == 1)
    return true;
  if (a[0] > a[1])
    return false;
  // n > 1
  // a[0] <= a[1]
  return sorted(a + 1, n - 1);
}

bool different(int a[], int n) {
  // !!!  return n <= 1 || (a[0] != a[1] && different(a + 1, n - 1));
  return n <= 1 || (!search(a + 1, n - 1, a[0]) && different(a + 1, n - 1));
}

// връща индекса на последния елемент в първата част на масива
int split(int a[], int n, int pivot) {
  int i = 0, j = n - 1;
  while (i != j)
    if (a[i] < pivot)
      // a[i] е в правилната част на масива
      i++;
    else
      // a[i] НЕ е в правилната част на масива
      if (a[j] >= pivot)
        // a[j] е в правилната част на масива
        j--;
      else
        // a[j] НЕ е в правилната част на масива
        // разменяме ги
        swap(a[i], a[j]);
  cout << "След разделянето масивът изглежда така: ";
  printArray(a, n);
  // i == j
  // не знаем a[i] в коя част на масива е
  if (a[i] < pivot)
    // a[i] е в първата част на масива
    return i;
  // a[i] е във втората част на масива
  return i - 1;
}

void quicksort(int a[], int n) {
  if (n <= 1)
    return;
  cout << "Започваме да сортираме следния масив: ";
  printArray(a, n);
  // n > 1
  // 1. избираме a[0] за ос
  int& pivot = a[0];
  cout << "Оста ни е: " << pivot << endl;
  // 2. разделяме масива на две части спрямо оста
  // lastless е индексът на последния елемент от първата част
  int lastless = split(a + 1, n - 1, pivot) + 1;
  cout << "Индексът на последния елемент от първата част е: " << lastless << endl;
  // 3. поставяме оста между двете части на масива
  // т.е. разменяме я с последния елемент от първата част
  swap(pivot, a[lastless]);
  // 4. сортираме рекурсивно двете части на масива без оста
  quicksort(a, lastless); // + 1 - 1
  quicksort(a + lastless + 1, n - 1 - lastless);
  cout << "Сортирахме масива: ";
  printArray(a, n);
}

void testarrays() {
  int a[MAX];
  int n = readArray(a);
  cout << "Сумата от елементите е " << sumArray(a, n) << endl;
  cout << "Числото 2 ";
  if (!search(a, n, 2))
    cout << "НЕ ";
  cout << "се среща в масива" << endl;
  cout << "Масивът ";
  if (!sorted(a, n))
    cout << "НЕ ";
  cout << "е сортиран" << endl;
  cout << "Масивът ";
  if (!different(a, n))
    cout << "НЕ ";
  cout << "се състои от различни елементи" << endl;
  quicksort(a, n);
  printArray(a, n);
}

int main() {
  // testrecursion();
  // testexpression();
  testarrays();
}
