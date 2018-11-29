#include <iostream>
using namespace std;

int main() {
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

      // transpose magic
      for(int i = 0; i < m; i++)
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
      
  return 0;
}
