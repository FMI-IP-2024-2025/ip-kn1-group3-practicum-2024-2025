#include <iostream>

int modifiedElementSum(int arr[], size_t size) {
  int sum = 0;
  for (size_t i = 0; i < size; ++i) {
    //по този начин не модифицираме елементите в масива директно
    if (i%6 == 0) {
      sum += arr[i]+1;
    }
    else if (i%3 == 0) {
      sum += arr[i]*2;
    }
    else if (i%2 == 0) {
      sum += arr[i];
    }
    else {
      sum += arr[i]%i;
    }
  }

  return sum;
}

int main() {

  int arr[18];
  for (int i = 0; i < 18; ++i) {
    arr[i] = i+1;
  }

  std::cout << modifiedElementSum(arr,18);

  return 0;
}