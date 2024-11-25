#include <iostream>

unsigned int const N = 3;

bool isSymmetric(int matrix[][N]) {
  for (unsigned int i = 0; i < N; ++i) {
    for (unsigned int j = i+1; j < N; ++j) {
      if (matrix[i][j] != matrix[j][i]) return false;
    }
  }
  return true;
}

int main() {

  int matrix[N][N] = { {1,2,3},
                       {2,5,6},
                       {3,6,9} };

  std::cout << isSymmetric(matrix);                      

  return 0;
}