#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

int main() {
  int n, m, *v;
  freopen("9.1.7.in", "r", stdin);
  std::cin >> n >> m;
  v = new int[n];
  std::fill(v, v + n, INT32_MAX / 2); 
  std::vector<std::vector<std::pair<int, int> > >
         e(n, std::vector<std::pair<int, int> >());
  for (int i = 0; i < m; ++i) {
    int v1, v2, c;
    std::cin >> v1 >> v2 >> c;
    e[v1].push_back(std::make_pair(v2, c));
    e[v2].push_back(std::make_pair(v1, c));
  }

  std::queue<int> q;
  q.push(4); v[4] = 0;
  while (!q.empty()) {
    int curr = q.front(); q.pop();
    for (std::pair<int, int> edge : e[curr]) {
      if (v[edge.first] > v[curr] + edge.second) {
        v[edge.first] = v[curr] + edge.second;
        q.push(edge.first);
      }
    }
  }
  for (int i = 0; i < n; ++i) std::cout << v[i] << " "; std::cout << std::endl;
  return 0;
}

