#include <iostream>

int count_nodes(int N, int *l, int *r, int root) {
  if (root == 0) return 0;
  return 1 + count_nodes(N, l, r, l[root]) + count_nodes(N, l, r, r[root]);
}

int main() {
  int N, *l, *r, root;
  std::cin >> N >> root;
  l = new int[N + 1];
  r = new int[N + 1];
  for (int i = 1; i <= N; ++i) std::cin >> l[i];
  for (int i = 1; i <= N; ++i) std::cin >> r[i];

  std::cout << count_nodes(N, l, r, root) << std::endl;

  delete l, r;
  return 0;
}

