#include <iostream>

int main() {

  unsigned int a, b;
  std::cin >> a >> b;

  // what is the problem with having 0 as an entry?
  if (a==0 || b==0) {
    std::cout << "No forbidden arithmetic, please.";
    return -1;
  }

  while (a != b) {
    if (a < b) {
      b -= a;
    }
    else {
      a -= b;
    }
  }

  std::cout << a;  // will be the same as b

  return 0;
}