#include <iostream>

using namespace std;

int main() {
  int n, *x, k, s, sum;
  cin >> n;
  x = new int[n];
  for (int i = 0; i < n; ++i) { x[i] = 1; if (i) cout << "+"; cout << x[i]; }; cout << endl;

  k = n;
  while (k > 1) {
    s = k - 2;
    while (!(s == 0 || (x[s-1] > x[s]))) s--;
    x[s]++;
    sum = 0;
    for (int i = s + 1; i < k; i++) sum += x[i];
    for (int i = 1; i <= sum; ++i) x[s+i] = 1;
    k = s + sum;
    for (int i = 0; i < k; ++i) {if (i) cout << "+"; cout << x[i]; } cout << endl;
  }
  return 0;
}

