#include <iostream>

unsigned int const M = 2;
unsigned int const N = 3;

void traverseRows(int matrix[][N]) {
  for (unsigned int i = 0; i < M; ++i) {
    for (unsigned int j = 0; j < N; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void traverseCols(int matrix[][N]) {
  for (unsigned int j = 0; j < N; ++j) {
    for (unsigned int i = 0; i < M; ++i) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  } 
}

int main() {

  int matrix[M][N];
  for (unsigned int i = 0; i < M; ++i) {
    for (unsigned int j = 0; j < N; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  traverseRows(matrix);
  traverseCols(matrix);

  return 0;
}