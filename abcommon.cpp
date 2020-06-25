#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int n,m,*x,*y,*xy,*c,cn, cx, cy;
  cin >> n >> m;
  x = new int[n]; y = new int[m];
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int j = 0; j < m; ++j) cin >> y[j];
  xy = new int[(n+1)*(m+1)];

  for (int i = 0; i < n; ++i)
  for (int j = 0; j < m; ++j) {
    if (x[i] == y[j]) {
      xy[(i+1)*(m+1) + j + 1] = xy[i*(m+1) + j] + 1;
    } else {
      xy[(i+1)*(m+1) + j + 1] = max(xy[i*(m+1) + j + 1], xy[(i+1)*(m+1) + j]);
    }
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) cout << xy[i * (m+1) + j] << " ";
    cout << endl;
  }

  cx = n; cy = m;
  cn = xy[cx * (m+1) + cy];
  c = new int[cn];
  while (xy[cx * (m+1) + cy] > 0) {
    if (x[cx - 1] == y[cy - 1]) {
      c[xy[cx * (m+1) + cy] - 1] = x[cx - 1];
    }
    if (xy[(cx-1) * (m+1) + cy] < xy[cx*(m+1) + cy - 1] || cx <= 1) {
      cy--;
    } else {
      cx--;
    }
  }

  for (int i = 0; i < cn; ++i) cout << c[i] << " "; cout << endl;

  delete x, y, xy, c;
  return 0;
}

