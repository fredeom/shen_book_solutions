#include <iostream>

class querytree {
  int n, *x, *t, st;

  void make_regular(int i);

public:
  querytree(int n, int *x);
  void put(int i, int val);
  int get(int i);
  int getMinIndex();
  void pd() {
    std::cout << "====================" << std::endl;
    for (int i = 0; i < n; ++i) std::cout << x[i] << " "; std::cout << "<= x " << n << " <= n" << std::endl;
    for (int i = 0; i < st; ++i) std::cout << t[i] << " "; std::cout << "<= t " << st << " <= st" << std::endl;
  }
};

void querytree::make_regular(int i) {
  i = (st >> 1) + i;
  int ti = i >> 1;
  bool value_comp = true;
  while (ti > 0) {
    if (value_comp) {
      if (t[2*ti] < t[2*ti + 1]) t[ti] = 2*ti; else t[ti] = 2*ti + 1;
      value_comp = false;
    } else if (t[t[2*ti]] < t[t[2*ti + 1]]) t[ti] = t[2*ti]; else t[ti] = t[2*ti + 1];
    ti = ti >> 1;
  }
}

querytree::querytree(int n1, int *x1) {
  n = n1;
  x = x1;

  st = 1;
  while (st < n) st += st;
  st += st;

  t = new int[st];
  for (int i = 0; i < n; ++i) t[(st >> 1) + i] = x[i];
  for (int i = (st >> 1) + n; i < st; i++) t[i] = INT32_MAX;
  for (int i = 0; i < n; i++) make_regular(i);
  pd();
}

void querytree::put(int i, int val) {
  int ti = (st >> 1) + i;
  t[ti] = val;
  x[i] = val;
  make_regular(i);
}

int querytree::get(int i) {
  return x[i];
}

int querytree::getMinIndex() {
  return t[1] - (st >> 1);
}

int main() {
  int n, *x;
  freopen("6.4.1.in", "r", stdin);
  std::cin >> n;
  x = new int[n];
  for (int i = 0; i < n; i++) std::cin >> x[i];

  //for (int i = 0; i < n; i++) std::cout << x[i] << " "; std::cout << std::endl;

  querytree qt(n, x);

  qt.put(3, 7);

  qt.pd();

  std::cout << qt.get(3) << std::endl;

  std::cout << qt.getMinIndex() << std::endl;

  return 0;
}

