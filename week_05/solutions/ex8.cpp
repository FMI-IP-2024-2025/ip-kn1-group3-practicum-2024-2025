#include <iostream>

bool isSorted(int arr[], size_t size) {
  for (size_t i = 1; i < size; ++i)
    if (arr[i-1] > arr[i]) return false;

  return true;
}

void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size-1; ++i) {
    for (int j = i+1; j < size; ++j) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int binarySearch(int arr[], int size, int el) {
  if (!isSorted(arr,size)) bubbleSort(arr,size);

  int beg = 0, end = size-1;

  while (beg <= end) {
    int mid = (beg+end)/2;
    if (arr[mid] == el) return mid;
    else if (arr[mid] < el) beg = mid+1;
    else end = mid-1;
  }

  return -1;
}

int main() {

  int arr[6] = {5,6,2,4,9,13};

  std::cout << binarySearch(arr,6,2);

  return 0;
}