#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
  int n, en = 0, *rem;
  vector<vector<int> > e;
  freopen("6.2.6.in", "r", stdin);
  cin >> n;
  rem = new int[n];
  for (int i = 0; i < n; ++i) {
    int m, k;
    vector<int> edges;
    cin >> m;
    en += m;
    for (int j = 0; j < m; ++j) {
      cin >> k;
      edges.push_back(k);
    }
    e.push_back(edges);
  }

  deque<int> d;
  d.push_back(0);
  while (d.size() < en) {
    int first = d.front();
    int last = d.back();
    if (e[last].size() > rem[last]) {
      int next = e[last][rem[last]];
      rem[last]++;
      if (next == first) {
        d.pop_front();
      }
      d.push_back(next);
    } else {
      for (int z : e[last])
        if (z == first) {
          d.pop_front();
          d.push_back(z);
          break;
        }
    }
  }
  for (int z : d) cout << z << " "; cout << endl;

  return 0;
}

