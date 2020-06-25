#include <iostream>
#include <algorithm>

using namespace std;

void handle(int n, int *x, int k, int nmax) {
  if (!n) {
    for (int i = 0; i < k; i++) {
      if (i) cout << "+";
      cout << x[i];
    }
    cout << endl;
    return;
  }
  for (int i = nmax; i > 0; i--) {
    x[k] = i;
    handle(n - i, x, k + 1, min(i, n - i));
  }
}

int main() {
  int n, *x, k, s, sum;
  cin >> n;
  x = new int[n];
  handle(n, x, 0, n);
  //for (int i = 0; i < n; ++i) { x[i] = 1; if (i) cout << "+"; cout << x[i]; }; cout << endl;
 /*
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
  */
  return 0;
}

// time to think about..
/*
4

4
3 1
2 2
2 1 1
1 1 1 1

*/
