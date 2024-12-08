#include <iostream>

bool goalSum(int arr[], int size, int index, int target) {
  if (target==0) return true; 
  if (target < 0) return false;

  bool res = false;
  //гарантирано е, че няма да изпаднем в безкрайна рекурсия,
  //тъй като числата в масива са положителни
  for (int i = index; i < size; ++i) {
    //избираме съответно дали искаме да включим arr[i]
    //в сумата многократно, дали искаме да го включим веднъж,
    //или изобщо не искаме да го включваме
    res = goalSum(arr,size,index,target-arr[i]) ||
          goalSum(arr,size,index+1,target-arr[i]) ||
          goalSum(arr,size,index+1,target);
  }

  return res;
}

int main() {

  unsigned int const SIZE = 1;
  int arr[SIZE] = {1};
  std::cout << goalSum(arr,SIZE,0,11);

  return 0;
}