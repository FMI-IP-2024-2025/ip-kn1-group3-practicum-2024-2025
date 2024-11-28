#include <iostream>

bool isPowerOf2(int n) {
  if (n<=0) return false;
  if (n==1) return true;
  if (n%2) return false;
  return isPowerOf2(n/2);
}

int main() {

  std::cout << std::boolalpha;
  std::cout << isPowerOf2(-2) << std::endl;
  for (unsigned int i = 0; i <= 1024; ++i) {
    if (isPowerOf2(i))
      std::cout << i << std::endl;
  }

  return 0;
}