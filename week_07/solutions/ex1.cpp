#include <iostream>

void divisors(int a, int b, int n) {
  for (int i = a; i <= b; ++i) {
    if (i != 0 && n%i == 0) 
      std::cout << i << '\n';
  }
}

int main() {

  divisors(-5,5,4);

  return 0;
}