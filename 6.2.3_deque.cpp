#include <iostream>

using namespace std;

class Deque {
  int *x;
  int n, f, len;
public:
  Deque(int n);
  bool isFull() { return (len == n); }
  bool isEmpty() { return (len == 0); }
  void push_back(int item);
  void push_front(int item);
  int pop_back();
  int pop_front();
};

Deque::Deque(int n1) {
  n = n1;
  x = new int[n];
  f = 0;
  len = 0;
}

void Deque::push_back(int item) {
  if (isFull()) { cout << "\nDeque overflow\n"; return; }
  x[(f + len) % n] = item;
  len++;
}

void Deque::push_front(int item) {
  if (isFull()) { cout << "\nDeque overflow\n"; return; }
  f = (f - 1 + n) % n;
  x[f] = item;
  len++;
}

int Deque::pop_back() {
  if (isEmpty()) { cout << "\nDeque underflow\n"; return INT32_MAX; }
  len--;
  return x[(f + len) % n];
}

int Deque::pop_front() {
  if (isEmpty()) { cout << "\nDeque underflow\n"; return INT32_MAX; }
  int tmp = x[f];
  f = (f + 1) % n;
  len--;
  return tmp;
}

int main() {
  Deque d(5);
  d.push_back(7);
  d.push_front(8);
  cout << d.pop_back() << endl;
  cout << d.pop_front() << endl;
  cout << d.pop_back() << endl;
  cout << d.pop_front() << endl;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  d.push_front(4);
  d.push_front(5);
  d.push_front(6);
  cout << d.pop_back() << endl;
  cout << d.pop_back() << endl;
  cout << d.pop_front() << endl;
  cout << d.pop_front() << endl;
  return 0;
}

