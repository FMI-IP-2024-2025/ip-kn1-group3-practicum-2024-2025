#include <iostream>

unsigned int const N = 3;

//първият вариант е сравнително по-неоптимален:
//състои се от транспониране на матрицата,
//сортиране на всеки от редовете ѝ,
//последвано от още едно транспониране.
//работи без допълнителна памет, 
//защото матрицата е квадратна
void bubbleSort(int arr[]) {
  for (int i = 0; i < N; ++i) {
    for (int j = i+1; j < N; ++j) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void transpose(int matrix[][N]) {
  for (unsigned int i = 0; i < N; ++i) {
    for (unsigned int j = i+1; j < N; ++j) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}

void sortColumns(int matrix[][N]) {
  transpose(matrix);
  for (int i = 0; i < N; ++i) {
    bubbleSort(matrix[i]);
  }
  transpose(matrix);
}

//втори вариант - директно сортираме колоните
void sortColumns2(int matrix[][N]) {
  for (unsigned int j = 0; j < N; ++j) {
    for (unsigned int i = 0; i < N; ++i) {
      for (unsigned int k = i+1; k < N; ++k) {
        if (matrix[i][j] > matrix[k][j]) {
          //разменя двете стойности. ще говорим за това по-нататък
          std::swap(matrix[i][j], matrix[k][j]);
        }
      }
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

  int matrix[N][N] = { {9,8,7},
                       {6,8,4},
                       {7,2,5} };

  sortColumns2(matrix);   
  print(matrix);                    

  return 0;
}