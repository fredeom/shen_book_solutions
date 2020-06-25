#include <iostream>

void generate(int k, int n, int *x, int ind) {
  if (ind > 0 && x[ind - 1] + k - 1 - ind > n) return;
  if (ind == k) {
    for (int i = 0; i < k; ++i) std::cout << x[i] << " "; std::cout << std::endl;
    return;
  }
  for (int i = ind == 0 ? 1 : x[ind - 1] + 1; i <= n - (k - 1 - ind); i++) {
    x[ind] = i;
    generate(k, n, x, ind + 1);
  }
}

int main() {
  int n, k, *x;
  std::cin >> n >> k;
  x = new int[k];
  generate(k, n, x, 0);
  return 0;
}

