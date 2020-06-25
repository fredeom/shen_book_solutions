#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[]) {
  int n, m, *x, l, r, q, nr;
  cin >> n >> m;
  x = new int[n+m];
  for (int i = 0; i < n + m; ++i) cin >> x[i];

  l = 0; r = n + m - 1; q = n;
  while (l + q - 1 < r) {
    if (2*q <= r - l + 1) {
      for (int k = l; k < l + q; ++k) {
        swap(x[k], x[k + q]);
      }
      l += q;
    } else {
      for (int k = r; k >= l + q; k--) {
        swap(x[k], x[l+q-r+k-1]);
      }
      nr = l + q - 1;
      q = 2*q - r - 1;
      r = nr;
    }

    for (int z = 0; z < n + m; ++z) cout << x[z] << " "; cout << endl;
  }

  delete x;
  return 0;
}

