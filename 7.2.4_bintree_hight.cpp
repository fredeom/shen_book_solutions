#include <iostream>
#include <algorithm>

int height(int N, int *l, int *r, int root) {
  if (root == 0) return 0;
  return std::max(height(N, l, r, l[root]), height(N, l, r, r[root])) + 1;
}

int main() {
  int N, *l, *r, root;
  std::cin >> N >> root;
  l = new int[N + 1];
  r = new int[N + 1];
  for (int i = 1; i <= N; i++) std::cin >> l[i];
  for (int i = 1; i <= N; i++) std::cin >> r[i];

  std::cout << height(N, l, r, root) - 1 << std::endl;

  delete l, r;
  return 0;
}

