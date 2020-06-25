#include <iostream>
#include <algorithm>

class kdeques {
  int *x, *next, *prev, *first, *last;
  int n, k, free;

public:
  kdeques(int n, int k);
  bool is_full() { return (free == -1); }
  bool is_empty(int z) { return (first[z] == -1 || last[z] == -1); }
  void push_back(int z, int v);
  int pop_back(int z);
  void push_front(int z, int v);
  int pop_front(int z);

  void print_debug(const char *s) {
    if (s) std::cout << "=================" << s << "=================" << std::endl;
    for (int i = 0; i < n; ++i) std::cout << x[i] << " "; std::cout << " <= x" << std::endl;
    for (int i = 0; i < n; ++i) std::cout << next[i] << " "; std::cout << " <= next" << std::endl;
    for (int i = 0; i < n; ++i) std::cout << prev[i] << " "; std::cout << " <= prev" << std::endl;
    for (int i = 0; i < k; ++i) std::cout << first[i] << " "; std::cout << " <= first" << std::endl;
    for (int i = 0; i < k; ++i) std::cout << last[i] << " "; std::cout << " <= last" << std::endl;
    std::cout << "free= " << free << std::endl;
    std::cout << "==================================" << std::endl;
  }
};

kdeques::kdeques(int n1, int k1) {
  n = n1;
  k = k1;
  x = new int[n];
  next = new int[n];
  prev = new int[n];
  first = new int[k];
  last = new int[k];
  std::fill(x, x + n, -1);
  std::fill(next, next + n, -1);
  std::fill(prev, prev + n, -1);
  std::fill(first, first + k, -1);
  std::fill(last, last + k, -1);
  for (int i = 0; i < n - 1; ++i) next[i] = i + 1;
  for (int i = 1; i < n; ++i) prev[i] = i - 1;
  free = 0;
}

void kdeques::push_back(int z, int v) {
  if (is_full()) { std::cout << "\nDeque overflow\n"; return; }
  int nov, posl;
  nov = free;
  free = next[free];
  if (is_empty(z)) {
    first[z] = nov;
    last[z] = nov;
    next[nov] = -1;
    prev[nov] = -1;
    x[nov] = v;
  } else {
    posl = last[z];
    next[posl] = nov;
    next[nov] = -1;
    prev[nov] = posl;
    x[nov] = v;
    last[z] = nov;
  }
}

int kdeques::pop_back(int z) {
  if (is_empty(z)) { std::cout << "\nDeque underflow\n"; return INT32_MAX; }
  int l = last[z], ret;
  ret = x[l];
  x[l] = -1;
  last[z] = prev[l];
  next[prev[l]] = -1;
  next[l] = free;
  free = l;
  return ret;
}

void kdeques::push_front(int z, int v) {
  if (is_full()) { std::cout << "\nDeque overflow\n"; return; }
  int nov, perv;
  nov = free;
  free = next[free];
  if (is_empty(z)) {
    first[z] = nov;
    last[z] = nov;
    next[nov] = -1;
    prev[nov] = -1;
    x[nov] = v;
  } else {
    perv = first[z];
    prev[perv] = nov;
    prev[nov] = -1;
    next[nov] = perv;
    x[nov] = v;
    first[z] = nov;
  }
}

int kdeques::pop_front(int z) {
  if (is_empty(z)) { std::cout << "\nDeque underflow\n"; return INT32_MAX; }
  int f = first[z], ret;
  ret = x[f];
  x[f] = -1;
  first[z] = next[f];
  prev[next[f]] = -1;
  next[f] = free;
  free = f;
  return ret;
}

int main() {
  kdeques kd(10, 3);

  kd.print_debug("Just created");

  kd.push_back(0, 1);
  kd.push_back(0, 2);
  kd.push_back(0, 3);

  kd.push_front(1, 4);
  kd.push_front(1, 5);
  kd.push_front(1, 6);

  kd.push_back(2, 7);
  kd.push_back(2, 8);
  kd.push_back(2, 9);

  kd.print_debug("After initialization");

  std::cout << kd.pop_front(0) << std::endl;
  std::cout << kd.pop_back(0) << std::endl;

  std::cout << kd.pop_front(1) << std::endl;
  std::cout << kd.pop_back(1) << std::endl;

  std::cout << kd.pop_front(0) << std::endl;
  std::cout << kd.pop_back(1) << std::endl;
  std::cout << kd.pop_front(2) << std::endl;
  std::cout << kd.pop_back(2) << std::endl;
  std::cout << kd.pop_front(2) << std::endl;
  std::cout << kd.pop_back(2) << std::endl;

  kd.print_debug("After popping");

  return 0;
}

