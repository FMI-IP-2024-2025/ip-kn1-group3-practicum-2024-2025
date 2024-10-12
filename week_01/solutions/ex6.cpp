#include <iostream>

int main() {

  double a, b, c;
  std::cin >> a >> b >> c;

  if (a+b>c && a+c>b && b+c>a) {
    std::cout << "That triangle exists.";
  }
  else {
    std::cout << "There doesn't exist such a triangle.";
  }

  return 0;
}