#include <iostream>

void RLE(unsigned int const arr[], unsigned int n) {
  //изпълняваме цикъла до n-1, тъй като, ако масивът
  //има нечетен брой елементи, последният елемент ще е
  //на четен индекс, а ние не искаме да го повтаряме
  for (unsigned int i = 0; i < n-1; i+=2) {
    for (unsigned int j = 0; j < arr[i]; ++j) {
      std::cout << arr[i+1] << ' ';
    }
  }
}

int main() {

  unsigned int const SIZE = 7;
  unsigned int arr[SIZE] {0,1,1,0,2,2,7};

  RLE(arr,SIZE);

  return 0;
}