#include <iostream>

/*
Напишете функция, която приема естествено число n
с различни цифри и връща ново число, което има същите цифри
като n, но в сортиран низходящо вид.
*/

int sortDigits(int n) {
 
  int nCpy = n;
  int sorted = 0;
  int prevGreatest = 10;
  
  while (nCpy) {

    int greatest = 0;
    int k = n;
    while (k) {
      int digit = k%10;
      if (digit > greatest && digit < prevGreatest) {
        greatest = digit;
      }
      k /= 10;
    }

    prevGreatest = greatest;
    sorted = sorted*10 + greatest;
    nCpy /= 10;
  }

  return sorted;
}

int main() {

  std::cout << sortDigits(163542987);

  return 0;
}