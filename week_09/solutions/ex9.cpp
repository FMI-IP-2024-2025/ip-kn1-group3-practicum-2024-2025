#include <iostream>

//примитивна рекурсия
double quotient(int arr[], int size) {
  if (size<=2) return static_cast<double>(arr[1]);
  return quotient(arr,size-2) / arr[size-1];
}

double wrapQuotient(int arr[], int size) {
  if (size%2==0) return quotient(arr,size);
  return quotient(arr,size-1);
}

//опашкова рекурсия
double helperQuotient(int arr[], int size, int index, double res) {
  if (index>=size) return res;
  return helperQuotient(arr,size,index+2,res/arr[index]);
}

double tailQuotient(int arr[], int size) {
  return helperQuotient(arr,size,3,static_cast<double>(arr[1]));
}

int main() {

  int arr[8] = {0,-8,0,4,0,2,0,-4};
  std::cout << wrapQuotient(arr,8) << ' ' << tailQuotient(arr,8);

  return 0;
}