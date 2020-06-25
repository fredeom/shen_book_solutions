#include <iostream>
#include <stack>
#include <vector>

int main() {
  int n, m;
  std::stack<int> zeroes;
  std::vector<int> ans;
  freopen("9.2.4.in", "r", stdin);
  std::cin >> n >> m;
  std::vector<std::vector<int> > e(n, std::vector<int>());
  std::vector<int> cnt(n, 0);
  for (int i = 0; i < m; ++i) {
    int v1, v2;
    std::cin >> v1 >> v2;
    e[v1].push_back(v2);
    cnt[v2]++;
  }
  for (int i = 0; i < n; ++i) if (cnt[i] == 0) zeroes.push(i);
  for (int i = 0; i < n; ++i) {
    if (zeroes.empty()) {
      std::cout << "Found cycle" << std::endl;
      exit(0);
    }
    int v = zeroes.top(); zeroes.pop();
    ans.push_back(v);
    for (int edge : e[v]) {
      cnt[edge]--;
      if (cnt[edge] == 0) zeroes.push(edge);
    }
  }
  for (int a : ans) std::cout << a << " "; std::cout << std::endl;
  return 0;
}

