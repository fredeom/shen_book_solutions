#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int n, *x, b, l, r;
  cin >> n >> b;
  x = new int[n];
  for (int i = 0; i < n; i++) cin >> x[i];

  l = -1; r = n - 1;
  while (l != r) {
    if (x[l + 1] <= b) l++; else
    if (x[r] >= b) r--; else {
      swap(x[l+1], x[r]);
      l++; r--;
    }
  }

  for (int l = 0; l < n; ++l) cout << x[l] << " "; cout << endl;

  return 0;
}

// 5 3
// 2 3 3 3 2
// 5 3
// 5 4 3 2 1
// 5 3
// 1 2 3 2 1

