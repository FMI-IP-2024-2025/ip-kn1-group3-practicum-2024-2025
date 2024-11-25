#include <iostream>

unsigned int const M = 3;
unsigned int const N = 4;

void addToFirst(int m1[][N], int m2[][N]) {
  for (unsigned int i = 0; i < M; ++i) {
    for (unsigned int j = 0; j < N; ++j) {
      m1[i][j] += m2[i][j];
    }
  }
}

void add(int m1[][N], int m2[][N], int res[][N]) {
  for (unsigned int i = 0; i < M; ++i) {
    for (unsigned int j = 0; j < N; ++j) {
      res[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

void print(int matrix[][N]) {
  for (unsigned int i = 0; i < M; ++i) {
    for (unsigned int j = 0; j < N; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

int main() {

  int m1[M][N] = { {1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12} };
  
  int m2[M][N] = { {1,1,1,1},
                   {1,1,1,1},
                   {1,1,1,1} };

  int res[M][N];                   
        
  addToFirst(m1,m2);
  print(m1);

  std::cout << std::endl;

  add(m1,m2,res);
  print(res);

  return 0;
}