#include <iostream>
using namespace std;

void testArrays() {
  const int MAX = 100;
  int a[MAX] = { 1, 2 }, b[MAX];
  // cout << (a == b) << endl; // !!!
  // cout << a << endl; // !!!

  int n;
  do {
    cout << "Моля, въведете брой елементи на масива: ";
    cin >> n;
  } while (n < 1 || n > MAX);
  // 1 <= n <= MAX
  // !!! int a[n]; // !!! variable-length array
  for(int i = 0; i < n; i++) {
    cout << "Моля ,въведете a[" << i << "] = ";
    cin >> a[i];
  }

  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += a[i];
  cout << "Сумата на елементите е " << sum << endl;

  int x;
  cout << "Моля, въведете число: ";
  cin >> x;

  int i = 0;
  while (i < n && a[i] != x)
    i++;
  // ДА: a[i] == x
  // НЕ: i == n

  cout << "Числото " << x;
  if (i == n)
    cout << " НЕ";
  cout << " се среща в масива" << endl;

  i = 0;
  while (i < n - 1 && a[i] <= a[i+1])
    i++;
  // ДА: i == n - 1
  // НЕ: a[i] > a[i+1]

  cout << "Числата в масива";
  if (i < n - 1)
    cout << " НЕ";
  cout << " образуват монотонно растяща редица" << endl;

  i = 0;
  int j;
  // Идея: търсим дали има i < j: a[i] == a[j]
  do {
    j = i + 1;
    // Фиксираме i и търсим дали има j > i: a[i] == a[j]
    while (j < n && a[i] != a[j])
      j++;
    // ДА: a[i] == a[j]
    // НЕ: j == n
    i++;
  } while (i < n - 1 && j >= n);
  // ДА, намерихме:       j < n
  // НЕ, не сме намерили: i >= n - 1

  if (i >= n - 1)
    cout << "Вярно е";
  else
    cout << "НЕ е вярно";
  cout << ", че всички елементи на масива са различни" << endl;

  
  for(int i = 0; i < n - 1; i++) {
    // намираме мястото на най-малкия елемент вдясно от чертата
    // да допуснем, че най-малкият елемент вдясно от чертата е a[i]
    int mini = i;
    for(int j = i + 1; j < n; j++)
      if (a[j] < a[mini])
        // имаме нов най-малък елемент
        mini = j;

    // и разменяме a[mini] с a[i]
    int tmp = a[i];
    a[i] = a[mini];
    a[mini] = tmp;
  }

  for(int i = 0; i < n; i++)
    cout << "a[" << i << "] = " << a[i] << endl;
}

void saw() {
  const int MAX = 100;
  // !!! int a[n];
  int a[MAX];
  int n;
  do {
    cout << "Моля, въведете брой елементи на масива: ";
    cin >> n;
  } while (n < 1 || n > MAX);
  // 1 <= n <= MAX
  // !!! int a[n]; // !!! variable-length array
  for(int i = 0; i < n; i++) {
    cout << "Моля ,въведете a[" << i << "] = ";
    cin >> a[i];
  }

  bool isSaw = true;
  int i = 1;
  /* if (a[i] > a[i-1] && a[i] > a[i+1])
     isSaw = true;
     else
     isSaw = false; */
  /*
  for(i = 1; isSaw && i < n; i += 2)
    // !!! isSaw = a[i] > a[i-1] && a[i] > a[i+1];
    if (!(a[i] > a[i-1] && (i == n - 1 || a[i] > a[i+1])))
      isSaw = false;

    // Граничен случай: i == n - 1
  //if (i == n - 1 && !(a[n-1] > a[n-2]))
  //  isSaw = false;
  */
  // bool type = a[0] < a[1];
  /*
  if (a[0] < a[1])
    type = true;
  else
    type = false;
  */
  /*
  while (i < n &&
         ((a[0] < a[1] && a[i] > a[i-1] && (i == n - 1 || a[i] > a[i+1])) ||
          (a[0] > a[1] && a[i] < a[i-1] && (i == n - 1 || a[i] < a[i+1]))))
    i += 2;
  */
  while (i < n - 1 &&
         (a[i] > a[i-1] && a[i] > a[i+1] ||
          a[i] < a[i-1] && a[i] < a[i+1]))
    i++;
  
  cout << "Редицата ";
  if (i < n - 1)
    cout << "НЕ ";
  cout << "e трион\n";
}

void merge() {
  const int MAX = 100;
  int a[MAX], b[MAX], c[2*MAX];
  int n, m;
  do {
    cout << "Моля, въведете брой елементи на масива a: ";
    cin >> n;
  } while (n < 1 || n > MAX);
  // 1 <= n <= MAX
  for(int i = 0; i < n; i++) {
    cout << "Моля ,въведете a[" << i << "] = ";
    cin >> a[i];
  }
  do {
    cout << "Моля, въведете брой елементи на масива b: ";
    cin >> m;
  } while (m < 1 || m > MAX);
  // 1 <= m <= MAX
  for(int i = 0; i < m; i++) {
    cout << "Моля ,въведете b[" << i << "] = ";
    cin >> b[i];
  }

  int i = 0, j = 0, k = 0;
  while (i < n && j < m)
    if (a[i] < b[j])
      // вземаме от a
      c[k++] = a[i++];
    else
      // вземаме от b
      c[k++] = b[j++];
  // i == n || j == m, но не и двете едновременно
  // остава да прехвърлим останалите елементи
  while (i < n)
    // вземаме от a
    c[k++] = a[i++];
  while (j < m)
    // вземаме от b
    c[k++] = b[j++];

  for(i = 0; i < m + n; i++)
    cout << c[i] << ' ';
  cout << endl;
}

int main() {
  //  testArrays();
  // saw();
  merge();
  return 0;
}
