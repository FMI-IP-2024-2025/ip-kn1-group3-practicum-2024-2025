#include <iostream>

void print(int arr[], bool subset[], int size) {
  std::cout << "{ ";
  for (int i = 0; i < size; ++i) 
    if (subset[i])
      std::cout << arr[i] << ' ';
  std::cout << '}' << std::endl;
}

void subsets(int arr[], int size, int index, bool subset[]) {
  print(arr,subset,size);

  for (int i = index; i < size; ++i) {
    subset[i] = true;
    subsets(arr,size,i+1,subset);
    subset[i] = false;
  }
}

int main() {
  
  int arr[3] = {1,2,3};
  bool subset[3] {};
  subsets(arr,3,0,subset);
  
  return 0;
}