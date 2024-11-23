#include <iostream>

/*
Напишете функция, която приема масив от 10 цели числа
и връща броя на различните стойности в него.
*/

const unsigned int SIZE = 10;

bool seen(int arr[], unsigned int i, int value) {
  for (unsigned int k = 0; k < i; ++k)
    if (arr[k] == value) return true;
  return false;
}

//ако не сме срещнали числото arr[i],
//изваждаме броя на всички срещания
unsigned int uniqueElements(int arr[]) {
  
  unsigned int counter = SIZE;
  for (unsigned int i = 0; i < SIZE; ++i) {
    if (seen(arr,i,arr[i])) continue;
    
    for (unsigned int k = i+1; k < SIZE; ++k) 
      if (arr[i] == arr[k]) counter--;
  }

  return counter;
}

//можем и просто да броим елементите, които не сме 
//срещали до момента
unsigned int uniqueElements2(int arr[]) {

  unsigned int counter = 0;
  for (unsigned int i = 0; i < SIZE; ++i) {
    if (seen(arr,i,arr[i])) continue;
    
    counter++;
  }

  return counter;
}

int main() {

  int arr[SIZE] = {2,1,4,2,1,3,5,1,2,3};
  std::cout << uniqueElements2(arr);

  return 0;
}