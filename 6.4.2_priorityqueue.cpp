#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class priority_queue {
  vector<pair<int, int> >  x;
  void restore_up(int i);
  void restore_down(int i);

public:
  void push(int p, int v);
  int pop();
};

void priority_queue::restore_up(int i) {
  int p = (i+1) >> 1;
  if ((x[p-1]).first < (x[i]).first) {
    swap(x[p-1], x[i]);
    restore_up(p-1);
  }
}

void priority_queue::restore_down(int i) {
  int left = 2*(i+1) - 1, right = 2*(i+1);
  if (right < x.size() && x[left].first < x[right].first && x[i].first < x[right].first) {
    swap(x[i], x[right]);
    restore_down(right);
  } else
  if (left < x.size() && (x[i].first < x[left].first)) {
    swap(x[i], x[left]);
    restore_down(left);
  }
}

void priority_queue::push(int p, int v) {
  x.push_back(make_pair(p, v));
  restore_up(x.size() - 1);
}

int priority_queue::pop() {
  int val = x.front().second;
  cout << "!" << x.front().first << " ";
  swap(x[0], x[x.size() - 1]);
  x.pop_back();
  restore_down(0);
  return val;
}

int main() {
  priority_queue pq;

  pq.push(1, 10);
  pq.push(2, 20);
  pq.push(3, 30);
  pq.push(1, 40);
  pq.push(2, 50);
  pq.push(3, 60);
/*
  pq.push(4, 10);
  pq.push(0, 20);
  pq.push(8, 30);
  pq.push(3, 40);
  pq.push(5, 50);
  pq.push(2, 60);
*/
  cout << pq.pop() << endl;
  cout << pq.pop() << endl;
  cout << pq.pop() << endl;
  cout << pq.pop() << endl;
  cout << pq.pop() << endl;
  cout << pq.pop() << endl;

  return 0;
}

