#include <iostream>

unsigned int const N = 3;

void transpose(int matrix[][N]) {
  for (unsigned int i = 0; i < N; ++i) {
    for (unsigned int j = i+1; j < N; ++j) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}

void print(int matrix[][N]) {
  for (unsigned int i = 0; i < N; ++i) {
    for (unsigned int j = 0; j < N; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

int main() {

  int matrix[N][N] = { {1,2,3},
                       {4,5,6},
                       {7,8,9} };

  transpose(matrix);
  print(matrix);

  return 0;
}