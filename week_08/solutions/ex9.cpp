#include <iostream>

unsigned int const N = 3;

//един готин начин да завъртим матрица на 90
//градуса по посока на часовниковата стрелка,
//е първо да я транспонираме, а след това
//да обърнем местата на колоните ѝ
void tranpose(int matrix[][N]) {
  for (unsigned int i = 0; i < N; ++i) {
    for (unsigned int j = i+1; j < N; ++j) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}

void rotate90DegreesClockwise(int matrix[N][N]) {
  tranpose(matrix);
  for (unsigned int j = 0; j < N/2; ++j) {
    for (unsigned int i = 0; i < N; ++i) {
      std::swap(matrix[i][j], matrix[i][N-1-j]);
    }
  }
}

void print(int matrix[][N]) {
  for (unsigned int i = 0; i < N; ++i) {
    for (unsigned int k = 0; k < N; ++k) {
      std::cout << matrix[i][k] << ' ';
    }
    std::cout << '\n';
  }
}

int main() {

  int matrix[N][N] = { {1,2,3},
                       {4,5,6},
                       {7,8,9} };

  rotate90DegreesClockwise(matrix);
  print(matrix);  

  return 0;
}