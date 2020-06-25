#include <iostream>
#include <queue>

int main() {
  int N, *l, *r, root;
  std::cin >> N >> root;
  l = new int[N+1];
  r = new int[N+1];
  for (int i=1; i<N+1; ++i) std::cin>>l[i];
  for (int i=1; i<N+1; ++i) std::cin>>r[i];
  
  std::queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int t = q.front(); q.pop();
    if (t != 0) std::cout << t << " ";
    if (l[t] != 0) q.push(l[t]);
    if (l[t] != 0) q.push(r[t]);
  }

  delete l, r;

  return 0;
}

