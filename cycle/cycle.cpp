#include <iostream>
#include <cmath>
using namespace std;
int avg() {
  double sum = 0, x;
  int n;
  cout << "Въведете брой числа: ";cin >> n;
  for(int i = 1; i <= n; i++) {
    cout << "Въведете число: ";
    cin >> x;
    sum += x;
  }
  cout << "Средно аритметично: " << sum / n << endl;
  return 0;
}

int fact() {
  int n;
  cout << "n = ";cin >> n;
  int result = 1;
  for(int i = 1; i <= n; i++)
    result *= i;
  cout << n << "! = " << result << endl;
  return 0;
}

int exp1() {
  int n;
  cout << "n = ";cin >> n;
  double x;
  cout << "x = ";cin >> x;
  double result = 0;
  for(int i = 0; i <= n; i++) {
    long fact = 1;
    for(int j = 1; j <= i; j++)
      fact *= j;
    result += pow(x, i) / fact;
  }
  cout << "result = " << result << endl;
  cout << "exp(x) = " << exp(x) << endl;
  return 0;
}

int exp2() {
  int n;
  cout << "n = ";cin >> n;
  double x;
  cout << "x = ";cin >> x;
  double result = 0, yi = 1;
  for(int i = 0; i <= n; i++, yi *= x / i)
    // result да е сумата до <i
    // yi да е i-тия общ член
    result += yi;
    // result да е сумата до i включително
    // yi да е (i+1)-вия общ член
  cout << "result = " << result << endl;
  cout << "exp(x) = " << exp(x) << endl;
  return 0;
}

int numbers() {
  int n;
  cout << "n = ";cin >> n;
  int max = n*n*n + 5*n - 8, count = 0;
  for(int i = 1; i < n; i++) {
    int xi = n*n*n + 5*i*i*n - 8*i;
    if (xi % 3 == 0)
      count++;
    if (xi > max)
      max = xi;
  }
  cout << "count = " << count << endl;
  cout << "max = " << max << endl;
  return 0;
}

int factwhile() {
  int n;
  cout << "n = ";cin >> n;
  int result = 1, i = 1;
  while(i <= n)
    result *= i++;
  cout << n << "! = " << result << endl;
  return 0;
}

int syracuse() {
  int n;
  cout << "Въведете n: ";cin >> n;
  int i = 0;
  while (n > 1) {
    if (n % 2 == 0) n /= 2;
    else           (n *= 3)++;
    cout << "n = " << n << endl;
    i++;
  }
  cout << "Направени " << i << " стъпки" << endl;
  return 0;
}

int avgwhile() {
  int n = 0;
  double x, s = 0;
  // !!! double n; n++;
  do {
    cout << "Моля, въведете число (0 за край): ";
    cin >> x;
    s += x;
    if (x != 0)
      n++;
  } while (x != 0);
  if (n == 0)
    cout << "Не са въведени числа!\n";
  else
    cout << "Средно аритметично: " << s / n << endl;
  return 0;
}

int exp3() {
  double eps;
  cout << "ε = ";cin >> eps;
  double x;
  cout << "x = ";cin >> x;
  double result = 0, yi = 1, i = 0;
  while (fabs(yi) >= eps) {
    // result да е сумата до <i
    // yi да е i-тия общ член
    result += yi;
    // result да е сумата до i включително
    // yi да е (i+1)-вия общ член
    yi *= x / ++i;
  } // fabs(yi) < eps
  cout << "result = " << result << endl;
  cout << "exp(x) = " << exp(x) << endl;
  return 0;
}

int prime() {
  int n;
  cout << "Моля, въведете число: ";cin >> n;
  // искаме да проверим, че n няма делител между 2 и n/2
  int d = 1;
  do d++; while(n % d != 0 && d <= n / 2);
  // има: n % d == 0
  // ||
  // няма: d > n/2
  // !!! при n == 2 и двете условия ще са изпълнени!
  cout << "Числото " << n;
  if (n == 1 || d <= n / 2) // има
    cout << " НЕ";
  cout << " е просто\n";
  return 0;
}

int sqrtx() {
  double eps;
  cout << "ε = ";cin >> eps;
  double x;
  cout << "Моля, въведете число: ";cin >> x;
  double yn = x, yn1;
  do {
    yn1 = yn; // запомни в yn1 старото yn
    yn = (yn1 + x / yn1) / 2; // сметни новото yn
  } while (fabs(yn - yn1) >= eps);
  // |yn-yn1| < eps
  cout << "yn = " << yn << endl;
  cout << "sqrt(x) = " << sqrt(x) << endl;
  return 0;
}

int pyramid() {
  int n;
  cout << "Моля, въведете число: ";cin >> n;
  for(int i = 1; i <= n; i++) {
    // извежда i-тия ред на пирамидата
    // числата от 1 до i
    for(int j = 1; j <= i; j++)
      cout << j << ' ';
    cout << endl;
  }
  return 0;
}

int countdown() {
  int m, s;
  cout << "Моля, въведете минути и секунди: "; cin >> m >> s;
  for(; m >= 0; m--) {
    for(; s >= 0; s--)
      // if (s < 10) ....
      cout << m << ':' << (s < 10 ? "0" : "") << s << endl;
    s = 59;                           
  }
  return 0;
}

  int domino() {
    int count = 0;
    for(int x = 0; x <= 6; x++)
      for(int y = 0; y <= x; y++) {
        cout << "+---+---+\n| " << x << " | " << y << " |\n+---+---+\n\n";
        count++;
      }
    cout << "Изведени " << count << " плочки\n";
    return 0;
  }

int main() {
  int n;
  cout << "Моля, въведете число: ";cin >> n;
  int m = 0;
  while (n > 0 && m == 0) {
    int d = n % 10;
    // да проверим дали d се среща някъде другаде в n
    n /= 10; // махаме d
    m = n; // работим с копие на n
    while (m > 0 && d != m % 10)
      m /= 10; // махаме поредната цифра
    // да, d се среща някъде другаде   : d == m % 10 
    // не, d не се среща никъде другаде: m == 0
    // !!! m == d == 0: фалшиво "да"
    // истинското "да": m > 0
  }
  // да, има еднакви цифри  : m > 0
  // не, няма еднакви цифри : n == 0
  cout << "В числото";
  if (m > 0)
    cout << " има";
  else
    cout << " НЯМА";
  cout << " еднакви цифри\n";
}
