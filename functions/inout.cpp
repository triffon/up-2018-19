#include <iostream>
using namespace std;

#include "functions.h"

// въвежда дробна координата coord на точка с име p
double readCoordinate(char p, char coord) {
  double n;
  cout << "Моля, въведете координата " << coord << " на точката " << p << ": ";
  cin >> n;
  return n;
}

// извежда лице на триъгълник
void printTriangleArea(double area) {
  cout << "Лицето на триъгълника е " << area << endl;
}
