#include <cmath>
#include "functions.h"

// пресмятане на полупериметъра
double cacluateHalfPerimeter(double a, double b, double c) {
  return (a + b + c) / 2;
}

// пресмята лице на триъгълник по дадени координати на върхове
double calculateTriangleArea(double xA, double yA,
                             double xB, double yB,
                             double xC, double yC) {
  // пресмятане на дължините на страните
  double a = calculateSegmentLength(xB, yB, xC, yC);
  double b = calculateSegmentLength(xA, yA, xC, yC);
  double c = calculateSegmentLength(xA, yA, xB, yB);
  
  // пресмятане на полупериметъра
  double p = cacluateHalfPerimeter(a, b, c);
  
  // формулата на Херон
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
