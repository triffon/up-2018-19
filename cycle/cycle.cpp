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

int main() {
  int n;
  cout << "n = ";cin >> n;
  int result = 1, i = 1;
  while(i <= n)
    result *= i++;
  cout << n << "! = " << result << endl;
  return 0;
}
