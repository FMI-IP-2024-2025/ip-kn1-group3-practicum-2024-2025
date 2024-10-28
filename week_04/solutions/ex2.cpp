#include <iostream>

unsigned int myAbs(int n) {
  return n > 0 ? n : -n;
}

// first way
unsigned int myAbsBitwise(int n) {
  return n + 2*n*(n >> 31 || 0)*-1;
}

// second way
unsigned int myAbsBitwise2(int n) {
  return (n >> 31 ^ n) - (n >> 31);
}

int main() {

  int n = -10;
  std::cout << myAbs(n) << ' ' 
            << myAbsBitwise(n) << ' '
            << myAbsBitwise2(n);

  return 0;
}