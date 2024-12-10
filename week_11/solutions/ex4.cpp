#include <iostream>

void secondaryDiagonal(int** matrix, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << matrix[i][n-1-i] << ' ';
  }
}

void belowSecondaryDiag(int** matrix, int n) {
  for (int i = 1; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      std::cout << matrix[j][n+i-j-1] << ' ';
    }
  }
}

int main() {

  int n;
  std::cin >> n;
  int** matrix = new int*[n];
  for (int i = 0; i < n; ++i) {
    matrix[i] = new int[n];
    for (int j = 0; j < n; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  secondaryDiagonal(matrix,n);
  std::cout << std::endl;
  belowSecondaryDiag(matrix,n);

  for (int i = 0; i < n; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;

  return 0;
}