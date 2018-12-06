#include <iostream>
using namespace std;

void testmatrices() {
  const int MAX = 100;
  int a[MAX][MAX], m, n;
  cout << "m = ";cin >> m;
  cout << "n = ";cin >> n;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
      cout << "a[" << i
           << "][" << j
           << "] = ";
              cin >> a[i][j];
    }

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++)
      cout << a[i][j] << '\t';
    cout << endl;
  }

  int sums[MAX] = {0};

  for(int j = 0; j < n; j++)
    for(int i = 0; i < m; i++)
      sums[j] += a[i][j];

  cout << "Суми по колони:\n";
  for(int j = 0; j < n; j++)
    cout << "sums[" << j << "] = " << sums[j] << endl;

  int x;
  cout << "x = ";cin >> x;

  for(int i = 0; i < m; i++) {
    int j = 0;
    while (j < n && a[i][j] != x)
      j++;
    if (j < n)
      cout << x << " се среща в ред " << i << endl;
  }

  int j = 0, min = 1;
  while (j < n && min % 2 != 0) {
    // намираме min = минималният елемент на колоната j
    min = a[0][j];
    for(int i = 1; i < m; i++)
      if (a[i][j] < min)
        min = a[i][j];
    j++;
  }

  // j == n || min % 2 == 0
  // min % 2 == 0 <-> min(a[0][j], a[1][j],..., a[m-1][j]) % 2 == 0
  if (min % 2 == 0)
    cout << "Колоната " << j-1 << " изпълнява условието\n";
  else
    cout << "Няма колона, която да изпълнява услоивието\n";
      
  // transpose magic
  for(int i = 0; i < m || i < n; i++)
    for(int j = 0; j < i; j++) {
      int tmp = a[i][j];
      a[i][j] = a[j][i];
      a[j][i] = tmp;
    }
  // !!! не работи правилно за матрица 3 x 4 !!!

  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      cout << a[i][j] << '\t';
    cout << endl;
  }
      
  return;
}

int main() {
  // testmatrices()
  const int MAX = 10;
  int a[MAX][MAX] = {0};
  int n;
  cout << "n = ";cin >> n;
  int count = 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      a[i][j] = count++;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout << a[i][j] << '\t';
    cout << endl;
  }

  // първо над главния диагонал
  // k := j - i e "номер" на диагонал
  // диагоналът с номер k започва от (0, k) и завършва на (n - 1 - k, n - 1)
  for(int k = 0; k < n; k++) {
    for(int j = k; j < n; j++)
      cout << a[j-k][j] << ' ';
    cout << endl;
  }

  // сега под главния диагонал
  // k := i - j e "номер" на диагонал
  // диагоналът с номер k започва от (k, 0) и завършва на (n - 1, n - 1 - k)
  for(int k = 1; k < n; k++) {
    for(int i = k; i < n; i++)
      cout << a[i][i-k] << ' ';
    cout << endl;
  }
}
