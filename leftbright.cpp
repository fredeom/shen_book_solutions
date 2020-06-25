#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int n, *x, b, k;
  cin >> n >> b;
  x = new int[n];
  for (int i = 0; i < n; i++) cin >> x[i];

  k = 0;
  for (int i = 0; i < n - k; ++i) {
    while (x[i] > b) {
      swap(x[i], x[n - (++k)]);
    }
  }
  k = -1;
  for (int i = n - 1; i > k; --i) {
    while (k+1 < i && x[i] < b) {
      swap(x[++k], x[i]);
    }
  }

  for (int l = 0; l < n; ++l) cout << x[l] << " "; cout << endl;

  return 0;
}

// 5 3 2 3 3 3 2
// 5 3 5 4 3 2 1
