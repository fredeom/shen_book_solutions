#include <iostream>

void generate(int n, int k, int *x, int ind) {
  if (ind + k > n || k < 0) return;
  if (ind == n) {
    for (int i = 0; i < n; ++i) std::cout << x[i] << " "; std::cout << std::endl;
    return;
  }
  x[ind] = 0;
  generate(n, k, x, ind + 1);
  x[ind] = 1;
  generate(n, k - 1, x, ind + 1);
}

int main() {
  int n, k, *x;
  std::cin >> n >> k;
  x = new int[n];
  generate(n, k, x, 0);
  delete x;
  return 0;
}

