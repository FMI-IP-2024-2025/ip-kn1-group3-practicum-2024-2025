#include <iostream>

void helperCollatz(unsigned int n, unsigned int i) {
  std::cout << n << std::endl;
  if (n==1 || i >= 500) return;
  else if (n%2==0) helperCollatz(n/2,i+1);
  else helperCollatz(3*n+1,i+1);
}

void collatzConjecture(unsigned int n) {
  return helperCollatz(n,0);
}

int main() {

  collatzConjecture(11);

  return 0;
}