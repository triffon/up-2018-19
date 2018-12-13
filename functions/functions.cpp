#include <iostream>
using namespace std;

#include "functions.h"

int triangleArea() {
  // прочитане на координатите на точките на триъгълника
  cout << "Моля, въведене координатите на върховете на триъгълника:\n";
  double xA = readCoordinate('A', 'x');
  double yA = readCoordinate('A', 'y');
  double xB = readCoordinate('B', 'x');
  double yB = readCoordinate('B', 'y');
  double xC = readCoordinate('C', 'x');
  double yC = readCoordinate('C', 'y');
  
  // пресмятане на лице
  double area = calculateTriangleArea(xA, yA, xB, yB, xC, yC);
  
  // извеждане на резултата
  printTriangleArea(area);
  return 0;
}
