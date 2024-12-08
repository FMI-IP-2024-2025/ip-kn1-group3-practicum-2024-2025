#include <iostream>

void print(int arr[], int size) {
  for (int i = 0; i < size; ++i) 
    std::cout << arr[i] << ' ';
  std::cout << std::endl;
}

void permute(int arr[], int size, int index) {
  if (index>=size-1) {
    print(arr,size);
    return;
  } 

  for (int i = index; i < size; ++i) {
    std::swap(arr[i],arr[index]);
    permute(arr,size,index+1);
    std::swap(arr[i],arr[index]);
  }
}

int main() {

  int arr[3] = {1,2,3};
  permute(arr,3,0);

  return 0;
}