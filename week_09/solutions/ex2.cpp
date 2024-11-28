#include <iostream>

//примитивна рекурсия
unsigned int tripleFactorial(int n) {
  if (n<=1) return 1;
  return n * tripleFactorial(n-3);
}

//опашкова рекурсия
unsigned int tailTripleFactorial(int n, unsigned int res) {
  if (n<=1) return res;
  return tailTripleFactorial(n-3,n*res);
}

int main() {

  std::cout << tripleFactorial(5) << ' ' << tailTripleFactorial(5,1) << std::endl;

  return 0;
}