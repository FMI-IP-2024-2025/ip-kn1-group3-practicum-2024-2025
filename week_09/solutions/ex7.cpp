#include <iostream>

void print(bool arr[], int size) {
  for (unsigned int i = 0; i < size; ++i) {
    std::cout << arr[i] << ' '; 
  }
  std::cout << std::endl;
}

void booleanVectors(bool vector[], int size, int index) {
  if (index>=size) {
    print(vector,size);
    return;
  }
  vector[index] = 0;
  booleanVectors(vector,size,index+1);
  vector[index] = 1;
  booleanVectors(vector,size,index+1);
}

int main() {

  unsigned int const N = 4;
  bool arr[N];
  booleanVectors(arr,N,0);

  return 0;
}