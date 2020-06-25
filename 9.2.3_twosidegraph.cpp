#include <iostream>
#include <queue>

int main() {
  int n, m, *v;
  freopen("9.2.3.in", "r", stdin);
  std::cin >> n >> m;
  std::vector<std::vector<int> > e(n, std::vector<int>());
  v = new int[n];
  for (int i = 0; i < m; i++) {
    int v1, v2;
    std::cin >> v1 >> v2;
    e[v1].push_back(v2);
    e[v2].push_back(v1);
  }

  std::queue<int> q;
  for (int i = 0; i < n; i++)
  if (v[i] == 0) {
    q.push(i); v[i] = 1;
    while (!q.empty()) {
      int curr = q.front(); q.pop();
      for (int edge : e[curr])
      if (v[edge] == 0) {
        v[edge] = v[curr] == 1 ? 2 : 1;
        q.push(edge);
      } else if (v[edge] != v[curr]) {
        std::cout << "Not two side graph" << std::endl;
        exit(0);
      }
    }
  }
  std::cout << "Two side graph" << std::endl;
  return 0;
}

