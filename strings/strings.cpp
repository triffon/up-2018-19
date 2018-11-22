#include <cstring>
#include <iostream>
using namespace std;

int main() {
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

  return 0;
}
