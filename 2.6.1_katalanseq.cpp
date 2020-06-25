#include <iostream>

using namespace std;

void draw(int n, int *x) {
  for (int i = 0; i < n; ++i) cout << x[2*i] << " " << x[2*i + 1] << " ";
  cout << endl;
}

int main() {
  int n, *x, k, last = false, z, sum;
  cin >> n;
  x = new int[2*n];
  for (int i = 0; i < n; ++i) {
    x[2*i] = 1;
    x[2*i + 1] = -1;
  }
  draw(n, x);
  while (!last) {
    k = 2*n -1;
    while (x[k] == -1) k--;
    while (k >= 0 && x[k] == 1) k--;
    if (k < 0) last = true; else {
      last = false;
      z = -1; sum = 0;
      while (z != k) sum += x[++z];
      x[k] = 1; sum += 2;
      while (k < 2*n - 1) {
        k++;
        if (sum > 0) x[k] = -1; else x[k] = 1;
        sum += x[k];
      }
      draw(n, x);
    }
  }
  return 0;
}

