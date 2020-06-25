#include <iostream>

using namespace std;

int leaves(int N, int *l, int *r, int root) {
  if (l[root] == 0 && r[root] == 0) return 1;
  return (l[root] != 0 ? leaves(N, l, r, l[root]) : 0) + (r[root] != 0 ? leaves(N, l, r, r[root]) : 0);
}

int main() {
  int N, *l, *r, root;
  cin >> N >> root;
  l = new int[N + 1];
  r = new int[N + 1];
  for (int i = 1; i <= N; ++i) cin >> l[i];
  for (int i = 1; i <= N; ++i) cin >> r[i];

  cout << leaves(N, l, r, root) << endl;

  delete l, r;
  return 0;
}

