#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int k, l, q, *x, *y, *z, k1, l1, s, t, i1, j1;
  cin >> k >> l >> q;
  x = new int[k]; y = new int[l]; z = new int[l];
  for (int i = 0; i < k; ++i) cin >> x[i];
  for (int i = 0; i < l; ++i) cin >> y[i];

  for (int i = 0; i < l; ++i) z[i] = q - y[l-i-1];

  //for (int i = 0; i < l; ++i) cout << z[i] << " "; cout << endl;

  k1 = l1 = 0; s = abs(x[0] - z[0]);

  while (k1 < k && l1 < l) {
    if (x[k1] < z[l1]) k1++; else
    if (x[k1] > z[l1]) l1++;
    if (k1 < k && l1 < l) {
      t = abs(x[k1] - z[l1]);
      if (t < s) {
        s = t;
        i1 = k1; j1 = l - l1 - 1;
        //cout << ">>>" << k1 << " " << l1 << " " << s << endl;
        if (!s) break;
      }
    }
  }

  cout << x[i1] + y[j1] << endl;

  return 0;
}

