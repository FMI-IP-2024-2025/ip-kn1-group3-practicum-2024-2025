#include <iostream>
#include <cstdint>  //алтернативно, <climits>

int maxpair(int const a[], int const b[], unsigned int na, unsigned int nb) {
  int maxProduct = INT32_MIN;  //или INT_MIN в <climits>
  for (unsigned int i = 0; i < na; ++i) {
    for (unsigned int j = 0; j < nb; ++j) {

      int product = a[i]*b[j];
      if (product > maxProduct)
        maxProduct = product; 
        
    }
  }
  return maxProduct;
}

int main() {

  int a[2] {-1,10};
  int b[3] {0,-100,2};

  std::cout << maxpair(a,b,2,3);

  return 0;
}