#include <iostream>

int sum(int n, int *x) {
  if (n == 1) return x[0];
  return x[n-1] + sum(n - 1, x);
}

int main() {
  int n, *x;
  std::cin >> n;
  x = new int[n];
  for (int i = 0; i < n; ++i) std::cin >> x[i];

  std::cout << sum(n, x) << std::endl;
  delete x;
  return 0;
}

