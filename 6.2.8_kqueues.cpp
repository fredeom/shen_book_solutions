#include <iostream>
#include <algorithm>

class kqueues {
  int *x, *next, *first, *last;
  int n, k, free;

public:
  kqueues(int n, int k);
  bool is_full() { return (free == -1); }
  bool is_empty(int z) { return (first[z] == -1); }
  void push(int z, int v);
  int front(int z);

  void print_debug() {
    for (int i = 0; i < n; ++i) std::cout << x[i] << " "; std::cout << " <= x" << std::endl;
    for (int i = 0; i < n; ++i) std::cout << next[i] << " "; std::cout << " <= next" << std::endl;
    for (int i = 0; i < k; ++i) std::cout << first[i] << " "; std::cout << " <= first" << std::endl;
    for (int i = 0; i < k; ++i) std::cout << last[i] << " "; std::cout << " <= last" << std::endl;
    std::cout << "free= " << free << std::endl;
  }
};

kqueues::kqueues(int n1, int k1) {
  n = n1;
  k = k1;
  x = new int[n];
  next = new int[n];
  first = new int[k];
  last = new int[k];
  std::fill(x, x + n, -1);
  std::fill(next, next + n, -1);
  std::fill(first, first + k, -1);
  std::fill(last, last + k, -1);
  for (int i = 0; i < n - 1; ++i) next[i] = i + 1;
  free = 0;
}

void kqueues::push(int z, int v) {
  if (is_full()) { std::cout << "\nDeque overflow\n"; return; }
  int nov, posl;
  nov = free;
  free = next[free];
  if (is_empty(z)) {
    first[z] = nov;
    last[z] = nov;
    next[nov] = -1;
    x[nov] = v;
  } else {
    posl = last[z];
    next[posl] = nov;
    next[nov] = -1;
    x[nov] = v;
    last[z] = nov;
  }
}

int kqueues::front(int z) {
  if (is_empty(z)) { std::cout << "\nDeque underflow\n"; return INT32_MAX; }
  int f = first[z], ret;
  ret = x[f];
  first[z] = next[f];
  next[f] = free;
  free = f;
  return ret;
}

int main() {
  kqueues kd(10, 3);

  kd.push(0, 1);
  kd.push(0, 2);
  kd.push(0, 3);

  kd.push(1, 4);
  kd.push(1, 5);
  kd.push(1, 6);

  kd.push(2, 7);
  kd.push(2, 8);
  kd.push(2, 9);

  kd.print_debug();

  std::cout << kd.front(0) << std::endl;
  std::cout << kd.front(0) << std::endl;

  std::cout << kd.front(1) << std::endl;
  std::cout << kd.front(1) << std::endl;

  std::cout << kd.front(0) << std::endl;
  std::cout << kd.front(1) << std::endl;
  std::cout << kd.front(2) << std::endl;
  std::cout << kd.front(2) << std::endl;
  std::cout << kd.front(2) << std::endl;
  std::cout << kd.front(2) << std::endl;

  kd.print_debug();

  return 0;
}

