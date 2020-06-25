#include <iostream>

using namespace std;

void next(int n, int *x, int i) {
  int j;
  if (i == n) {
    for (i = 0; i < n; ++i) cout << x[i] << " "; cout << endl;
  }
  for (int k = 0; k < n; ++k) {
    for (j = 0; j < i; ++j) {
      if (x[j] == k + 1) break;
    }
    if (j == i) {
      x[i] = k+1;
      next(n, x, i + 1);
    }
  }
}

int main(int argc, char *argv[]) {
  int n, *x;
  cin >> n;
  x = new int[n];
  next(n, x, 0);
  return 0;
}

