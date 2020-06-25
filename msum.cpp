#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m, *x, s = 0;
  cin >> n >> m;
  x = new int[n];
  for (int i = 0; i < n; ++i) cin >> x[i];

  for (int i = 0; i < n; ++i) {
    s += x[i];
    if (i >= m) s -= x[i - m];
    if (i >= m - 1) cout << s << " ";
  }
  cout << endl;
  delete x;
  return 0;
}

