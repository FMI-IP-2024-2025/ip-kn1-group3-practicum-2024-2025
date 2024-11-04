#include <iostream>

//assuming beg and end are valid indices
bool isStrictlyIncreasing(int arr[], int beg, int end) {
  for (int i = beg+1; i <= end; ++i) {
    if (arr[i-1] >= arr[i]) return false;
  }
  return true;
}

bool isStrictlyDecreasing(int arr[], int beg, int end) {
  for (int i = beg+1; i <= end; ++i) {
    if (arr[i-1] <= arr[i]) return false;
  }
  return true;
}

bool isUnimodal(int arr[], int size, int i, int j) {
  //boundary checking
  if (i < 0 || j < 0) return false;
  if (i >= size || j >= size) return false;

  //това е, защото всяка редица от един елемент е едновременно
  //и (строго) растяща и (строго) намаляваща, т.е. можем да разделим
  //редица от един елемент на едноелементна такава и празната рецица,
  //за която по-горното също е тривиално вярно.
  if (size <= 1 || i == j) return true;

  for (int k = i; k < j; ++k) {
    if (isStrictlyIncreasing(arr,i,k) &&
        isStrictlyDecreasing(arr,k+1,j)) 
      
      return true;
  }

  return false;
}

int main() {

  std::cout << std::boolalpha;
  //строго растящите редици са в частност унимодални.
  //аналогично и за строго намаляващите
  int arr1[4] = {1,2,3,4};
  std::cout << isUnimodal(arr1,4,0,3) << '\n'; //t

  int arr2[6] = {1,5,6,3,4,1};
  std::cout << isUnimodal(arr2,6,0,5) << '\n'; //f
  std::cout << isUnimodal(arr2,6,0,3) << '\n'; //t
  std::cout << isUnimodal(arr2,6,3,5) << '\n'; //t

  int arr3[1] = {1};
  std::cout << isUnimodal(arr3,1,0,0) << '\n'; //t

  int arr4[3] = {1,1,1};
  std::cout << isUnimodal(arr4,3,0,2) << '\n'; //f

  int arr5[4] = {1,2,1,4};
  for (int i = 0; i < 4; ++i) {
    //t, t, t, f
    std::cout << isUnimodal(arr5,4,0,i) << '\n'; 
  }

  return 0;
}