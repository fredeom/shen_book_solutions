#include <iostream>

using namespace std;

void draw(int n, int *x, int *d) {
  for (int i = 0; i < n; ++i) cout << x[i] << " "; cout << " >>> ";
  for (int i = 0; i < n; ++i) cout << d[i] << " "; cout << endl;
}

int main() {
  int n, k, *x, *d, p, z;
  cin >> n >> k;
  x = new int[n]; d = new int[n];
  for (int i = 0; i < n; ++i) {
    x[i] = 1;
    d[i] = 1;
  }
  draw(n, x, d);
  p = true;
  while (p) {
    z = n - 1;
    while ((z > 0) && (((d[z] == 1) && (x[z] == k)) || ((d[z] == -1) && (x[z] == 1)))) z--;

    if ((d[z] == 1 && x[z] == k)||(d[z] == -1 && x[z] == 1)) p = false; else {
      p = true;
      x[z] += d[z];
      for (int j = z + 1; j < n; ++j) d[j] = - d[j];
      draw(n, x, d);
    }
  }
  return 0;
}

