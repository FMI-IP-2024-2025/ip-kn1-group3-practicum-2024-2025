#include <iostream>

//примитивна рекурсия
double quickPow(double base, int exp) {
  if (exp==0) return 1;
  if (exp%2==0) return quickPow(base*base,exp/2);
  return base * quickPow(base,exp-1);
}

//опашкова рекурсия
double helperQuickPow(double base, int exp, double res) {
  if (exp==0) return res;
  if (exp%2==0) return helperQuickPow(base*base,exp/2,res);
  return helperQuickPow(base,exp-1,res*base);
}

double tailQuickPow(double base, int exp) {
  return helperQuickPow(base,exp,1);
}

int main() {

  std::cout << quickPow(2,11) << ' ' << tailQuickPow(2,11) << std::endl;

  return 0;
}