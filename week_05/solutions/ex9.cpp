#include <iostream>

size_t longestNonDecreasingSubsequence(int arr[], size_t size) {
  size_t longest = 1, current = 1;
  for (size_t i = 1; i < size; ++i) {
    if (arr[i-1] <= arr[i]) current++;
    else {
      if (current > longest) {
        longest = current; 
      }
      current = 1;
    }
  }

  return longest > current ? longest : current;
}

int main() {

  size_t const SIZE = 10;
  int arr[SIZE] = {6,3,4,5,2,3,4,5,5,3};
  std::cout << longestNonDecreasingSubsequence(arr,SIZE);

  return 0;
}