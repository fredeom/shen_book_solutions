#include <iostream>
#include <algorithm>

using namespace std;

void draw(int n, int *x) {
  for (int i = 0; i < n; ++i) cout << x[i]+1 << " ";
  cout << endl;
}

int main() {
  int n, *x, *inv_x, *y, *d, b = true, z, pos1, pos2, val1, val2;
  cin >> n;
  x = new int[n]; inv_x = new int[n]; y = new int[n]; d = new int[n];
  for (int i = 0; i < n; ++i) {
    x[i] = n - 1 - i;
    inv_x[i] = n - 1 - i;
    y[i] = 0;
    d[i] = 1;
  }
  draw(n, x);
  while (b) {
    z = n - 1;
    while (z > 0 && ((d[z] == 1 && y[z] == z)||(d[z]==-1 && y[z]==0))) z--;
    b = z > 0;
    if (b) {
      y[z] = y[z] + d[z];
      for (int j = z + 1; j < n; ++j) d[j] = -d[j];
      pos1 = inv_x[z];
      val1 = z;
      pos2 = pos1 + d[z];
      val2 = x[pos2];
      swap(x[pos1], x[pos2]);
      swap(inv_x[val1], inv_x[val2]);
      draw(n, x);
    }
  }
  delete x, inv_x, y, d;
  return 0;
}

