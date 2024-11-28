#include <iostream>

//примитивна рекурсия
unsigned int steps(unsigned int n) {
  if (n <= 1) return 1;
  return steps(n-1) + steps(n-2);
}

//опашкова рекурсия
unsigned int helperSteps(unsigned int n, unsigned int curr, unsigned int prev) {
  if (n<=1) return curr;
  return helperSteps(n-1,curr+prev,curr);
}

unsigned int tailSteps(unsigned int n) {
  //можем и да инициализираме prev параметъра с 0,
  //ако искаме да започнем първото число на Фибоначи
  //да е 0
  return helperSteps(n,1,1);
}

int main() {

  std::cout << steps(15) << ' ' << tailSteps(15) << std::endl;

  return 0;
}