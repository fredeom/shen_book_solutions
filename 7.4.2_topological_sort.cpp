#include <iostream>
#include <vector>

void printt(int n, int *p, std::vector<std::vector<int> >& e, int ind) {
 if (p[ind]) return;
 for (int edge : e[ind]) {
   printt(n, p, e, edge);
 }
 if (!p[ind]) {
   std::cout << ind << " ";
   p[ind] = true;
 }
}

int main() {
  int n, *p;
  std::vector<std::vector<int> > e;
  freopen("7.4.2.in", "r", stdin);
  std::cin >> n;
  p = new int[n];
  for (int i = 0; i < n; ++i) {
    int m;
    std::vector<int> edges;
    std::cin >> m;
    while (m--) {
      int tmp;
      std::cin >> tmp;
      edges.push_back(tmp);
    }
    e.push_back(edges);
  }
  for (int i = 0; i < n; ++i) printt(n, p, e, i);
  std::cout << std::endl;
  return 0;
}

