#include <iostream>
#include <vector>
#include <utility>
#include <queue>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int> > >
    e(n, std::vector<std::pair<int, int> >());
  std::vector<int> x(n, -1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    e[a].push_back(std::make_pair(b, c));
  }

  std::queue<int> q;
  q.push(0); x[0] = 0;
  while (!q.empty()) {
    int c = q.front(); q.pop();
    for (std::pair<int, int> p : e[c]) {
      if (x[p.first] < 0 || x[c] + p.second < x[p.first] ) {
        x[p.first] = x[c] + p.second;
        q.push(p.first);
      }
    }
  }

  std::cout << x[n - 1] << std::endl;

  return 0;
}

