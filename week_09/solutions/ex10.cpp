#include <iostream>

bool existsTargetSum(int arr[], int size, int index, int target) {
  if (target == 0) return true;
  if (target < 0 || index>=size) return false;

  return existsTargetSum(arr,size,index+1,target-arr[index])
      || existsTargetSum(arr,size,index+1,target);
}

int main() {

  unsigned int const SIZE = 4;
  int arr[SIZE] = {1,4,7,9};
  std::cout << existsTargetSum(arr,SIZE,0,13);

  return 0;
}