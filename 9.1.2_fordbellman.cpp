#include <iostream>

int main() {
  int n, m, *x, *a;
  freopen("9.1.2.in", "r", stdin);
  std::cin >> n >> m;
  a = new int[n*n];
  x = new int[n];
  for (int i = 0; i < m; ++i) {
    int a1, b1, c1;
    std::cin >> a1 >> b1 >> c1;
    a[a1 * n + b1] = c1;
  }
  for (int i = 0; i < n*n; ++i)
    if (a[i] == 0 && i / n != i % n) a[i] = INT32_MAX / 2;
  for (int i = 0; i < n; ++i) x[i] = a[i];
  for (int k = 0; k < n; ++k) {
    for (int s = 0; s < n; ++s) {
      for (int i = 0; i < n; ++i) {
        if (x[s] > x[i] + a[i*n + s]) {
          x[s] = x[i] + a[i*n + s];
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) std::cout << x[i] << " ";
  std::cout << std::endl;
  return 0;
}

