#include <iostream>

void enumerate(int n, int k) {
  if (n == 0) { std::cout << std::endl; return; }
  for (int i = 1; i < k + 1; ++i) {
    std::cout << i << " ";
    enumerate(n - 1, k);
  }
}

void generate(int n, int k, int *x, int ind) {
  if (ind == n) {
    for (int i = 0; i < n; ++i) std::cout << x[i] << " "; std::cout << std::endl;
  } else {
    for (int i = 1; i < k + 1; i++) {
      x[ind] = i;
      generate(n, k, x, ind + 1);
    }
  }
}

int main() {
  int n, k, *x;
  std::cin >> n >> k;
  x = new int[n];

  generate(n, k, x, 0);

  return 0;
}

