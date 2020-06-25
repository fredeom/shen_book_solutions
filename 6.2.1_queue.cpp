#include <iostream>

using namespace std;

class Queue {
  int *x;
  int n, f, len;

public:
  Queue(int n1);
  void push(int item);
  int pop_first();
  bool isEmpty() { return (len == 0); }
  bool isFull() { return (len == n); }
};

Queue::Queue(int n1) {
  n = n1;
  x = new int[n];
  f = 0;
  len = 0;
}

void Queue::push(int item) {
  if (isFull()) { cout << "\nQueue overflow\n"; return; }
  x[(f + len) % n] = item;
  len++;
}

int Queue::pop_first() {
  if (isEmpty()) { cout << "\nQueue underflow\n"; return INT32_MAX; }
  int tmp = x[f];
  f = (f + 1) % n;
  len--;
  return tmp;
}

int main() {
  Queue q(5);
  q.push(7);
  q.push(10);
  q.push(15);
  cout << q.pop_first() << endl;
  cout << q.pop_first() << endl;
  q.push(123);
  q.push(23);
  q.push(3);
  cout << q.pop_first() << endl;
  cout << q.pop_first() << endl;
  q.push(11);
  q.push(12);
  q.push(13);
  q.push(14);
  cout << q.pop_first() << endl;
  cout << q.pop_first() << endl;
  cout << q.pop_first() << endl;
  cout << q.pop_first() << endl;
  cout << q.pop_first() << endl;
  cout << q.pop_first() << endl;
  cout << q.pop_first() << endl;

  return 0;
}

