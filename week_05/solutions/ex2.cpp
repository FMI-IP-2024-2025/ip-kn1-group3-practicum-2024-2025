#include <iostream>

int findSmallest(int arr[], size_t size) {
  int smallest = arr[0];
  for (size_t i = 1; i < size; ++i) {
    if (arr[i] < smallest) 
      smallest = arr[i];
  }
  return smallest;
}

int findBiggest(int arr[], size_t size) {
  int biggest = arr[0];
  for (size_t i = 1; i < size; ++i) {
    if (arr[i] > biggest)
      biggest = arr[i];
  }
  return biggest;
}

//в случая не броим елементите с една и съща стойност
//за различни елементи, т.е. вторият най-голям елемент в
//масива {5,5,3} ще е 3.
int findSecondBiggest(int arr[], size_t size) {
  int biggest = findBiggest(arr,size);
  int secondBiggest = arr[0];
  for (size_t i = 1; i < size; ++i) {
    if (arr[i] > secondBiggest && arr[i] < biggest) 
      secondBiggest = arr[i];
  }
  return secondBiggest;
}

int main() {

  size_t const SIZE = 8;
  int arr[SIZE] = {3,13,42,90,90,23,51,66};

  std::cout << findBiggest(arr,SIZE) << ' '
            << findSmallest(arr,SIZE) << ' '
            << findSecondBiggest(arr,SIZE);

  return 0;
}