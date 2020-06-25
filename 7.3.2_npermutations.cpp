#include <iostream>

void generate(int n, int *x, int ind) {
  if (ind == n + 1) {
    for (int i = 1; i < n + 1; i++) std::cout << x[i] << " "; std::cout << std::endl;
    return;
  }
  for (int i = 1; i < n + 1; ++i) {
    if (x[i] == 0) {
      x[i] = ind;
      generate(n, x, ind + 1);
      x[i] = 0;
    }
  }
}

int main() {
  int n, *x;
  std::cin >> n;
  x = new int[n + 1];
  generate(n, x, 1);
  return 0;
}

