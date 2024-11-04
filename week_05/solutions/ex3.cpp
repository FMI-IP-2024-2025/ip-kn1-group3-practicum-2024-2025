#include <iostream>

//идеята е просто да преместим всичките елементи след 
//подадения индекс с едно наляво
void removeElement(int arr[], size_t size, size_t index) {
  for (size_t i = index; i < size-1; ++i) {
    arr[i] = arr[i+1];
  }
}

void printArr(int arr[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    std::cout << arr[i] << '\n';
  }
}

int main() {

  size_t const SIZE = 10;
  int arr[SIZE] = {1,50,2,3,4,5,6,7,8,9};
  removeElement(arr,SIZE,1);
  //вече сме "премахнали" един елемент,
  //така че размерът е с едно по-малко
  printArr(arr,SIZE-1);

  return 0;
}