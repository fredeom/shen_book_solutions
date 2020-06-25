#include <iostream>
#include <algorithm>

void generate(int n, int *x, int ind) {
  if (n == 0) {
    for (int i = 0; i < ind; i++) std::cout << x[i] << " "; std::cout << std::endl;
    return;
  }
  for (int i = ind == 0 ? n : std::min(x[ind - 1], n); i > 0; i--) {
    x[ind] = i;
    generate(n - i, x, ind + 1);
  }
}

int main() {
  int n, *x;
  std::cin >> n;
  x = new int[n];
  generate(n, x, 0);
  return 0;
}

