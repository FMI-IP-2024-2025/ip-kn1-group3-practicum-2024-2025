#include <iostream>

unsigned int const M = 3;
unsigned int const N = 4;

void spiralMatrixTraversal(int matrix[M][N]) {
  int startRow = 0, startCol = 0;
  int endRow = M-1, endCol = N-1;
  
  while (startRow <= endRow && startCol <= endCol) {

    for (int i = startCol; i <= endCol; ++i) {
      std::cout << matrix[startRow][i] << ' ';
    }
    startRow++;

    for (int i = startRow; i <= endRow; ++i) {
      std::cout << matrix[i][endCol] << ' ';
    }
    endCol--;

    if (startRow <= endRow) {
      for (int i = endCol; i >= startCol; --i) {
        std::cout << matrix[endRow][i] << ' ';
      }
      endRow--;
    }

    if (startCol <= endCol) {
      for (int i = endRow; i >= startRow; --i) {
        std::cout << matrix[i][startCol] << ' ';
      }
      startCol++;
    }
  }
}

int main() {

  int matrix[M][N] = { {1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12} };

  spiralMatrixTraversal(matrix);                       

  return 0;
}