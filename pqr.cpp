#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int p,q,r,*x,*y,*z, p1, q1, r1, exist = false;
  cin >> p >> q >> r;
  x = new int[p]; y = new int[q]; z = new int[r];

  for (int i = 0; i < p; ++i) cin >> x[i];
  for (int i = 0; i < q; ++i) cin >> y[i];
  for (int i = 0; i < r; ++i) cin >> z[i];

  p1 = q1 = r1 = 0;
  while (p1 < p && q1 < q && r1 < r) {
    if (x[p1] < y[q1] || x[p1] < z[r1]) p1++;
    if (x[p1] > y[q1] || y[q1] < z[r1]) q1++;
    if (z[r1] < y[q1] || x[p1] > z[r1]) r1++;
    if (x[p1] == y[q1] && y[q1] == z[r1]) {
      cout << x[p1] << endl;
      exist = true;
      break;
    }
  }
  if (!exist) cout << "No" << endl;

  delete x;
  delete y;
  delete z;
  return 0;
}

