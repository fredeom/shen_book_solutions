#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[]) {
  int k, l, m = 0, *x, *y, *z, k1, l1;
  cin >> k >> l;
  x = new int[k]; y = new int[l]; z = new int[max(k, l)];
  for (int i = 0; i < k; ++i) cin >> x[i];
  for (int i = 0; i < l; ++i) cin >> y[i];

  cout << l << " " << k << endl;

  k1 = 0; l1 = 0;
  while (k1 < k && l1 < l) {
    while (k1 < k && x[k1] < y[l1]) k1++;
    while (l1 < l && x[k1] > y[l1]) l1++;
    while (k1 < k && l1 < l && x[k1] == y[l1]) {
      z[m++] = x[k1++]; l1++;
    }
  }
  for (l1 = 0; l1 < m; ++l1) cout << z[l1] << " "; cout << endl;
}

