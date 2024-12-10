#include <iostream>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {

  int x = 10, y = 20;
  swap(x,y);
  std::cout << x << ' ' << y << std::endl;

  int* p1 = &x, *p2 = &y;
  swap(p1,p2);
  std::cout << x << ' ' << y << std::endl;

  return 0;
}