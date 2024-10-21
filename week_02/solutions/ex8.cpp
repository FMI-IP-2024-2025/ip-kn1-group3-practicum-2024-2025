#include <iostream>

int main() {

  // assuming valid entry
  unsigned int perimeter;
  std::cin >> perimeter;

  unsigned int counter = 0;

  for (int a = 1; a <= perimeter/3; ++a) {
    for (int b = a; a+b < perimeter; ++b) {
      int c = perimeter-a-b;
      if (a+b<=c || a+c<=b || b+c<=a) continue;
      if (a<=b && b<=c) {
        ++counter;
        std::cout << a << '+' << b << '+' << c << '=' << perimeter << '\n';
      }
    }
  }

  // you can also use the ternary operator,
  // but it doesn't look as clean
  if (counter) {
    std::cout << "There exist a total of " << counter
              << " triangle/s with a perimeter of "
              << perimeter;
  }
  else {
    std::cout << "There don't exist any triangles "
              << "with a perimeter of " << perimeter;
  }

  return 0;
}