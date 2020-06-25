#include <iostream>

int main() {
  int n, k, *x;
  std::cin >> n >> k;
  x = new int[(n+1)*(n+1)];
  for (int i = 0; i <= n; i++) {
  for (int j = 0; j <= i; j++) {
    x[(i-j) * (n+1) + j] = (j == 0 || j == i) ? 1:
                       x[(i-j)*(n+1) + j - 1] + x[(i - j - 1)*(n+1) + j];
    std::cout << x[(i-j)*(n+1) + j] << " ";
  }
  std::cout << std::endl;
  }
  //for (int i = 0; i <= n; i++) {
  //  for (int j = 0; j <= i; j++) std::cout << x[(i - j) * n + j] << " ";
  //  std::cout << std::endl;
  //}
  std::cout << x[(n - k) * (n+1) + k] << std::endl;
  delete x;
  return 0;
}

