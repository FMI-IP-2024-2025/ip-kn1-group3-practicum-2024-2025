#include <iostream>

size_t intersect(int arr1[], size_t size1,
int arr2[], size_t size2, int intersection[]) {
  size_t counter = 0;
  for (size_t i = 0; i < size1; ++i) {
    for (size_t j = 0; j < size2; ++j) {
      if (arr1[i] == arr2[j])
        intersection[counter++] = arr1[i];
    }
  }

  return counter;
}

int main() {

  size_t const SIZE1 = 5;
  int arr1[SIZE1] = {1,2,3,4,5};
  size_t const SIZE2 = 3;
  int arr2[SIZE2] = {5,2,3};
  //тъй като сечението не може да бъде с размер,
  //по-голям от този на по-малкия масив
  int intersection[SIZE1<SIZE2 ? SIZE1 : SIZE2];
  size_t interesectionSize = intersect(arr1,SIZE1,arr2,SIZE2,intersection);

  for (size_t i = 0; i < interesectionSize; ++i) {
    std::cout << intersection[i] << ' ';
  }

  return 0;
}