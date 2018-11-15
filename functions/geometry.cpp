#include <cmath>
#include "functions.h"

double calculateHypothenuse(double a, double b) {
  return sqrt(a * a + b * b);
}

double calculateSegmentLength(double x1, double y1,
                              double x2, double y2) {
  return calculateHypothenuse(x2 - x1, y2 - y1);
}
