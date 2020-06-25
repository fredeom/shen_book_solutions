#include <iostream>

using namespace std;

class kStacks {
  int *x;
  int *top;
  int *next;

  int n, k;
  int free;

public:
  kStacks(int k, int n);
  bool isFull () { return (free == -1); }
  void push(int item, int sn);
  int pop(int sn);
  bool isEmpty(int sn) { return (top[sn] == -1); }

  void debug_print() {
    cout << "x= "; for (int i = 0; i < n; i++) cout << x[i] << " "; cout << endl;
    cout << "top= "; for (int i = 0; i < k; i++) cout << top[i] << " "; cout << endl;
    cout << "next= "; for (int i = 0; i < n; i++) cout << next[i] << " "; cout << endl;
    cout << "free= " << free << endl;
  }
};

kStacks::kStacks(int k1, int n1) {
  k = k1, n = n1;
  x = new int[n];
  top = new int[k];
  next = new int[n];
  for (int i = 0; i < k; i++) top[i] = -1;
  free = 0;
  for (int i = 0; i < n - 1; i++) next[i] = i + 1; next[n-1] = -1;
}

void kStacks::push(int item, int sn) {
  if (isFull()) { cout << "\nStack Overflow\n"; return; }
  int i = free;
  free = next[i];
  next[i] = top[sn];
  top[sn] = i;
  x[i] = item;
  debug_print();
}

int kStacks::pop(int sn) {
  if (isEmpty(sn)) { cout << "\nStack Underflow\n"; return INT32_MAX; }
  int i = top[sn];
  top[sn] = next[i];
  next[i] = free;
  free = i;
  return x[i];
}

int main() {
  kStacks ks(3, 10);
  ks.push(15, 2);
  ks.push(45, 2);
  ks.push(17, 1);
  ks.push(49, 1);
  ks.push(39, 1);
  ks.push(11, 0);
  ks.push(9, 0);
  ks.push(7, 0);
  cout << ks.pop(2) << endl;
  cout << ks.pop(1) << endl;
  cout << ks.pop(0) << endl;
  return 0;
}

