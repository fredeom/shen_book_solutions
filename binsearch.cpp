#include <iostream>

using namespace std;

int main(int argc, char*argv[]) {
  int n, *x, a, l, r, mid;
  cin >> n >> a;
  x = new int[n];
  for (int i = 0; i < n; ++i) cin >> x[i];
  l = 0; r = n;
  while (l+1 < r) {
    mid = (l + r) / 2;
    if (x[mid] > a) r = mid; else l = mid;
  }
  if (x[l] == a) cout << "In"; else cout << "Out"; cout << endl;
  return 0;
}

