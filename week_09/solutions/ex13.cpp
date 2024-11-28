#include <iostream>
#include <cmath>

unsigned int const SIZE = 4;

int sign(int i) {
  if (i%2==0) return 1;
  return -1;
}

int determinant(int matrix[][SIZE], int size) {
  if (size==1) return matrix[0][0];

  if (size==2) return matrix[0][0] * matrix[1][1]
                    - matrix[0][1] * matrix[1][0];

  int res = 0;
  int minor[SIZE][SIZE];
  for (int i = 0; i < size; ++i) {

    int minorRow = 0;
    for (int row = 1; row < size; ++row) {
      int minorCol = 0;

      for (int col = 0; col < size; ++col) {
        if (i==col) continue;
        minor[minorRow][minorCol] = matrix[row][col];
        minorCol++;
      }
      
      minorRow++;
    }

    res += sign(i)*matrix[0][i]*determinant(minor,size-1);
  } 

  return res;
}

int main() {

  int matrix[SIZE][SIZE] = {{1,3,5,9},{1,3,1,7},{4,3,9,7},{5,2,0,9}};

  std::cout << determinant(matrix,SIZE);

  return 0;
}