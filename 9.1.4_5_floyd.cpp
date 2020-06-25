#include <iostream>
#include <algorithm>
#include <iomanip>

int main() {
  int n, m, *A;
  freopen("9.1.4.in", "r", stdin);

  std::cin >> n >> m;

  A = new int[n*n];

  std::fill(A, A + n*n - 1, INT32_MAX / 2 );

  for (int i = 0; i < m; i++) {
    int z, x, c;
    std::cin >> z >> x >> c;
    A[z * n + x] = c;
    A[x * n + z] = c;
  }

  for (int i = 0; i < n; ++i) A[i*n + i] = 0;

  for (int k = 0; k < n; k++)
  for (int i = 0; i < n; ++i)
  for (int j = 0; j < n; ++j) {
    A[i * n + j] = std::min(A[i * n + j], A[i * n + k] + A[k * n + j]);
    if (i == j && A[i * n + j] < 0) {
      std::cout << "Negative cycle found" << std::endl;
      exit(0);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      std::cout << std::setw(4) << (A[i * n + j] > INT32_MAX / 4 ? -1 : A[i*n +j]) << " ";
    std::cout << std::endl;
  }

  return 0;
}

