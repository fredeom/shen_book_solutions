#include <iostream>

using namespace std;

void draw(int k, int *x) {
  for (int i = 0; i < k; ++i) {
    if (i) cout << "+";
    cout << x[i];
  }
  cout << endl;
}

int main() {
  int n, *x, k, i;
  cin >> n;
  for (int i = 0; i < n; ++i) x[i] = 1;

  draw(n, x);

  k = n;
  while (true) {
    if (k == 1) break;
    i = k - 2;
    x[i]++; x[i+1]--;
    if (x[i] > x[i+1]) {
      x[i] += x[i+1];
      k--;
    } else {
      while (x[k-1] >= 2*x[k-2] ) {
        x[k] = x[k-1] - x[k-2];
        x[k-1] = x[k-2];
        k++;
      }
    }
    draw(k, x);
  }
  return 0;
}

