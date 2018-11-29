#include <cstring>
#include <iostream>
using namespace std;

void teststrings() {
  // !!! char word[5] = "Hello";
  // !!! char word[5] = { 'H', 'e', 'l', 'l', 'o' };
  const int MAX = 10;
  char word[MAX] = "Hello";
  char word2[MAX] = "why?";
  cout << word << endl; // cin >> word;
  cin.getline(word, MAX);
  //cin.getline(word2, MAX);
  cout << word << '-' << word2 << endl;
  cout << strcpy(word2, word) << endl;
  cout << word[0] << endl;
  word[1] = 'o';
  // !!! strcpy(word, "AAAAAAAAAA");
  cout << word << '-' << word2 << endl;
  cout << "Въведени са " << strlen(word) << " символа\n";
  // word = "Ho, world!\n";
  // word2 = "Hi, world!\n";
  cout << "Сравнение: " << strcmp(word, word2) << endl;
  if (strcmp(word, word2) < 0)
    cout << word << " е преди " << word2 << endl;
  else if (strcmp(word, word2) > 0)
    cout << word2 << " е преди " << word << endl;
  else
    cout << word << " и " << word2 << " съвпадат" << endl;
}

void mystrfunctions() {
  const int MAX = 101;
  char s[MAX] = "";
  cin.getline(s, MAX);

  int i = 0;
  // !!! while(s[i++]);
  while(s[i])
    i++;

  cout << "Дължината на " << s << " е " << i << endl;

  char s2[MAX] = "Hello, world!";
  i = 0;
  // !!! while(i < strlen(s))
  while (s[i]) {
    s2[i] = s[i];
    i++;
  }
  // s[i] == '\0';
  s2[i] = '\0';

  cout << s2 << endl;

  s[2] = 'o';

  while (s[i] && s[i] == s2[i])
    i++;
  // !s[i] || !s2[i] || s[i] != s2[i]
  cout << s[i] - s2[i] << endl;
}

void strfunctions() {
  const int MAX = 101;
  char s1[MAX] = "", s2[MAX] = "";
  cin.getline(s1, MAX);
  cin.getline(s2, MAX);

  cout << strcat(s1, s2) << endl;

  if (strchr(s1, 'l'))
    cout << strchr(s1, 'l') << endl;
  else
    cout << "В низа няма 'l'\n";

  if (strstr(s1, ", "))
    cout << strstr(s1, ", ") << endl;
  else
    cout << "В низа няма \", \"\n";

  cout << s1[0] << ' ' << s1[2] << endl;
  cout << strlen(s1) << endl;
}

void checkpalindrome() {
  const int MAX = 101;
  char s[MAX] = "";
  cin.getline(s, MAX);

  int n = strlen(s), i = 0;
  while (i < n / 2 && s[i] == s[n - 1 - i])
    i++;

  cout << '"' << s << "\" ";
  if (i < n / 2)
    cout << "НЕ ";
  cout << "е палиндром" << endl;

  for(int i = 0; i < n; i++)
    cout << (int)s[i] << ' ';
  cout << endl;
}

int isletter(char c) {
  return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

void countwords() {
  const int MAX = 101;
  char s[MAX] = "";
  cin.getline(s, MAX);

  int count = 0, i = 0;
  bool onWord = false; // onWord == true <-> последният разгледан символ е буква
  while (s[i]) {
    // magic
    // :( if (!isletter(s[i]))
    // :(  count++;
    // !!! if (!isletter(s[i-1]) && isletter(s[i]))
    if (!onWord && isletter(s[i]))
      count++;
    onWord = isletter(s[i]);
    i++;
  }
  cout << "В \"" << s << "\" има " << count << " думи" << endl;
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

void calculator() {
  const int MAX = 101;
  char s[MAX] = "";
  cout << "> ";
  cin.getline(s, MAX);

  int result = 0, i = 0;
  char op = '+';
  int arg = 0; // <result> <op> <arg>
  while(s[i]) {
    // magic
    if (isop(s[i])) {
      // извършвам операцията
      result = calculate(result, op, arg);
      // запомням новата операция
      op = s[i];
      arg = 0;
    } else {
      // s[i] е цифра
      arg *= 10;
      arg += todigit(s[i]);
    }     
    i++;
  }
  cout << result << endl;
}

void strnfunctions() {
  const int MAX = 101;
  char s1[MAX] = "", s2[MAX];
  cin.getline(s1, MAX);
  strncpy(s2, s1, 10);
  s2[10] = '\0'; // сигурни сме, че низът е терминиран
  cout << "s2 = " << s2 << endl;
}

int main() {
  // teststrings();
  // mystrfunctions();
  // strfunctions();
  // checkpalindrome();
  // countwords();
  // calculator();
  strnfunctions();
  return 0;
}
