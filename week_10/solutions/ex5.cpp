#include <iostream>

void print(int arr[], int size, bool indices[]) {
  for (int i = 0; i < size; ++i) 
    if (indices[i]) std::cout << arr[i] << ' ';
  std::cout << std::endl;
}

bool goalSum(int arr[], int size, int index, int target, bool indices[]) {
  if (target==0) {
    print(arr,size,indices);
    return true;
  }
  if (target<0 || index>=size) return false;

  indices[index] = true;
  bool res = goalSum(arr,size,index+1,target-arr[index],indices);
  indices[index] = false;
  //забележете, че res не може да е първо! ако res вече е true,
  //то изобщо няма да направим рекурсивното извикване, а искаме
  //да изведем всички начини да бъде образувана сумата
  res = goalSum(arr,size,index+1,target,indices) || res;

  return res;
}

int main() {

  unsigned int const SIZE = 7;
  int arr[SIZE] = {1,4,7,9,13,12,13};
  bool indices[SIZE] {};
  std::cout << goalSum(arr,SIZE,0,13,indices);

  return 0;
}