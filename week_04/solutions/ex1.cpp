#include <iostream>

double const PI = 3.14;

double circleArea(double radius) {
  if (radius < 0) {
    throw std::invalid_argument("Radius cannot be negative");
  }

  double area = PI * radius * radius;
  return area;
}

int main() {

  double area = circleArea(3);
  std::cout << area << '\n';

  //don't worry about this too much :D
  try {
    double area2 = circleArea(-1);
  }
  catch (std::exception const& e) {
    std::cout << e.what();
  }

  return 0;
}