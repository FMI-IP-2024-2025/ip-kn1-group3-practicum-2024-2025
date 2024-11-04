#include <iostream>

int find(int arr[], unsigned int size, int el) {
  for (unsigned int i = 0; i < size; ++i)
    if (arr[i] == el) return i;
  
  return -1;
}

int rfind(int arr[], int size, int el) {
  for (int i = size-1; i >= 0; --i) 
    if (arr[i] == el) return i;

  return -1;
}

int main() {

  int arr[10] = {5,42,70,2,56,23,42,10,111,3};
  std::cout << find(arr,10,42) << ' ' << rfind(arr,10,42) << '\n';
  std::cout << find(arr,10,39) << ' ' << rfind(arr,10,39) << '\n';

  return 0;
}