#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char*argv[]) {
  int n, m, *x, *ml, *mr, mx;
  cin >> n >> m;
  x = new int[n];
  for (int i=0; i<n; i++) cin >> x[i];

  ml = new int[n]; mr = new int[n];
  for (int i=0; i<n; i++) {
    if (!(i % m)) mx = x[i]; else
    if (x[i] > mx) mx = x[i];
    ml[i] = mx;
  }
  for (int i=n-1; i>=0; --i) {
    if (!((n-1-i) % m)) mx = x[i]; else
    if (x[i] > mx) mx = x[i];
    mr[i] = mx;
  }

  for (int i = 0; i < n-m+1; ++i) {
    cout << max(mr[i], ml[i+m-1]) << " ";
  }

  cout << endl;

  delete x, ml, mr;
  return 0;
}

