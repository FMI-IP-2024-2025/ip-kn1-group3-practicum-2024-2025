#include <iostream>
#include <cmath>

/*
Напишете функция, която приема две естествени числа
n и k с равен брой цифри и без повтарящи се цифри във всяко от тях. 
Функцията трябва да върне броя на цифрите, 
които се съдържат и в двете числа, но са на различни позиции.
*/

//по принцип в задачата е гарантирано, че n и k ще са неотрицателни,
//но в общия случай е добре да си гарантираме, че цифрите ще бъдат неотрицателни
bool isContained(int n, int digit) {
  n = abs(n);
  while (n) {
    if ((n%10) == digit) return true;
    n/=10;
  }
  return false;
}

unsigned int sameValueDifferentPos(unsigned int n, unsigned int k) {

  int nCpy = n;
  int counter = 0;
  while (n && k) {
    if (n%10 != k%10 && isContained(nCpy, k%10))
      counter++;

    n/=10;
    k/=10;
  }

  return counter;
}

int main() {

  std::cout << sameValueDifferentPos(12346,12435);

  return 0;
}