#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m, a, **x, l, k;
  cin >> n >> m >> a;
  x = new int*[n];
  for (int i = 0; i < n; ++i) {
    x[i] = new int[m];
    for (int j = 0; j < m; ++j) cin >> x[i][j];
  }


  l = n - 1; k = 0;
  while (l >= 0 && k < m && x[l][k] != a) {
    if (x[l][k] < a) k++;
    if (x[l][k] > a) l--;
  }
  if (l >= 0 && k < m) cout << "In"; else cout << "Out"; cout << endl;
  return 0;
}

