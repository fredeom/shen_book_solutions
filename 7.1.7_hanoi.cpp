#include <iostream>

using namespace std;


void f(int i, int m, int n) {
  if (i == 1) {
    cout << m << " -> " << n << endl;
  } else {
    int s = 6 - m - n;
    f(i - 1, m, s);
    cout << m << " -> " << n << endl;
    f(i - 1, s, n);
  }
}

int main() {
  int n;
  cin >> n;
  f(n, 1, 3);
  return 0;
}

