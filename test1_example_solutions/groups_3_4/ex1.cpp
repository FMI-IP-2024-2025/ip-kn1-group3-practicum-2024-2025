#include <iostream>

/*
Напишете функция, която приема две естествени числа
n и k. Функцията трябва да провери дали
всяка цифра x в n се съдържа поне x пъти в k.
*/

//вътрешният while цикъл може и да се изнесе в отделна функция
bool atLeastXOccurences(int n, int k) {
  
  while (n) {
    int digit = n%10;
    int counter = 0, kcpy = k;
    while (kcpy) {
      if (kcpy%10 == digit) counter++;
      kcpy /= 10;
    }

    if (counter < digit) return false;
    n /= 10;
  } 

  return true;
}

int main() {

  std::cout << atLeastXOccurences(123, 21231323);

  return 0;
}