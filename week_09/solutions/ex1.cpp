#include <iostream>

//тук приемаме, че входът е валиден.
//в противен случай не бихме могли да използваме
//unsigned int, тъй като ще попаднем
//в безкрайна рекурсия

//примитивна рекурсия
unsigned int sum(unsigned int n) {
  if (n==0) return 0;
  return n + sum(n-1);
}

//опашкова рекурсия
unsigned int tailSum(unsigned int n, unsigned int res) {
  if (n==0) return res;
  return tailSum(n-1,res+n);
}

int main() {

  std::cout << sum(10) << ' ' << tailSum(10,0) << std::endl;

  return 0;
}