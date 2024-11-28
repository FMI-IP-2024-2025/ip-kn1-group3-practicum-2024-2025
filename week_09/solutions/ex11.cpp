#include <iostream>

unsigned int const SIZE = 5;

void primaryDiagonal(int matrix[][SIZE], int arr[], int index) {
  if (index>=SIZE) return;
  arr[index] = matrix[index][index];
  primaryDiagonal(matrix,arr,index+1);
}

int main() {

  int matrix[SIZE][SIZE] = { {1,2,3,4,5},
                             {6,7,8,9,10},
                             {11,12,13,14,15},
                             {16,17,18,19,20},
                             {21,22,23,24,25} };

  int diag[SIZE];
  primaryDiagonal(matrix,diag,0);                             
  for (unsigned int i = 0; i < SIZE; ++i)
    std::cout << diag[i] << ' ';
    
  return 0;
}