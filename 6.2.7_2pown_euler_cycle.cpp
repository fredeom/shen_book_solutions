#include <iostream>
#include <deque>
#include <algorithm>

void print_4(int ct, int n) {
  std:: cout << ct << " => ";
  for (int i = 0 ; i < n; i++) {
    std::cout << ct % 2;
    ct /= 2;
  }
  std::cout << std::endl;
}

void dfs(int last, int n, int *rem, int st) {
  for (; rem[last] < 2;) {
    int k = (last * 2 + rem[last]) % st;
    int ct = last * 2 + rem[last];
    rem[last]++;
    dfs(k, n, rem, st);
    print_4(ct, n);
  }
}


void dfs_non_recursive(int n, int *rem, int st) {
  bool is_first = true;
  std::deque<int> d;
  d.push_back(0);
  while (true) {
    int last = d.back();
    if (!is_first && !last) break; else is_first = false;
    d.pop_back();
    if (rem[last] == 0) {
      d.push_back((last * 2 + (rem[last]++)) % (st + st));
      d.push_back((last * 2 + (rem[last]++)) % (st + st));
      print_4(last, n);
    };
  }
}

int main() {
  int st = 1, n, *rem;
  std::cin >> n;
  for (int i = 1; i < n; i++) st += st;
  rem = new int[st + st];
  std::fill(rem, rem + st + st, 0);
  dfs_non_recursive(n, rem, st);
  //std::fill(rem, rem + st + st, 0);
  //dfs(0, n, rem, st);
  return 0;
}

