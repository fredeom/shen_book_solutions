#include <iostream>

int nheight(int N, int *l, int *r, int root, int n) {
  if (root == 0) return 0;
  return n == 0 ? 1 : nheight(N, l, r, l[root], n - 1) + nheight(N, l, r, r[root], n - 1);
}

int main() {
  int N, *l, *r, root, n;
  std::cin >> N >> root >> n;
  l = new int[N+1];
  r = new int[N+1];
  for (int i = 1; i <= N; i++) std::cin >> l[i];
  for (int i = 1; i <= N; i++) std::cin >> r[i];

  std::cout << nheight(N, l, r, root, n) << std::endl;

  delete l,r;

  return 0;
}

