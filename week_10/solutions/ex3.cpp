#include <iostream>

unsigned int const M = 3;
unsigned int const N = 3;

bool isValidMove(int i, int j) {
  if (i < 0 || i >= M) return false;
  if (j < 0 || j >= N) return false;
  return true;
}

bool existsPath(bool matrix[M][N], int i, int j) {
  if (!isValidMove(i,j)) return false;
  if (matrix[i][j] == 1) return false;
  if (i == M-1 && j == N-1) return true;

  matrix[i][j] = true;

  bool res = existsPath(matrix,i-1,j) || 
             existsPath(matrix,i,j+1) ||
             existsPath(matrix,i+1,j) ||
             existsPath(matrix,i,j-1); 

  matrix[i][j] = false;
  return res;
}

int main() {

  bool matrix[M][N] = { {0,0,1},
                        {1,0,1},
                        {0,0,0} };

  std::cout << existsPath(matrix,0,0) << std::endl;

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}