#include <iostream>

//примитивна рекурсия
int difference(int arr[], int size, int index) {
  if (index>=size-1) return arr[index];
  return difference(arr,size,index+1) - arr[index];
}

//опашкова рекурсия
int helperDifference(int arr[], int size, int res) {
  if (size<=0) return res;
  return helperDifference(arr,size-1,res-arr[size-1]);
}

int tailDifference(int arr[], int size) {
  return helperDifference(arr,size-1,arr[size-1]);
}

int main() {

  unsigned int const SIZE = 10;
  int arr[SIZE] = {1,2,3,4,5,6,7,8,9,-10};
  std::cout << difference(arr,SIZE,0) << ' ' << tailDifference(arr,SIZE);

  return 0;
}