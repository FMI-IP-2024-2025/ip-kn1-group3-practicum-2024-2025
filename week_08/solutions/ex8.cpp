#include <iostream>

unsigned int const M = 2;
unsigned int const N = 3;
unsigned int const K = 2;

void multiply(int m1[M][N], int m2[N][K], int res[M][K]) {
  for (unsigned int i = 0; i < M; ++i) {
    for (unsigned int k = 0; k < K; ++k) {
      for (unsigned int j = 0; j < N; ++j) {
        //тук е важно res да е с инициализирани с 0 полета!
        res[i][k] += m1[i][j] * m2[j][k];
      }
    }
  }
}

void print(int matrix[M][K]) {
  for (unsigned int i = 0; i < M; ++i) {
    for (unsigned int k = 0; k < K; ++k) {
      std::cout << matrix[i][k] << ' ';
    }
    std::cout << '\n';
  }
}

int main() {

  int m1[M][N] = { {1,2,3},
                   {4,5,6} };

  int m2[N][K] = { {1,2},
                   {3,4},
                   {5,6} };

  int res[M][K] {};  
  multiply(m1,m2,res);
  print(res);                                  

}