#include <iostream>

using namespace std;

void draw(int n, int *x[]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << (x[i][j] ? "Q" : "-");
    cout << endl;
  }
  cout << endl;
}

void step(int n, int *x[], int *xp, int *xd, int i) {
  if (i == n) {
    draw(n, x);
  } else {
    for (int j = 0; j < n; ++j) {
      int xpInd = n + j, xd1 = i + 1 + j, xd2 = 2*n - 1 + j + n - i;
      if (!xp[xpInd] && !xd[xd1] && !xd[xd2]) {
        x[i][j] = 1;
        xp[xpInd]++; xd[xd1]++; xd[xd2]++;
        step(n, x, xp, xd, i + 1);
        xp[xpInd]--; xd[xd1]--; xd[xd2]--;
        x[i][j] = 0;
      }
    }
  }
}

int main() {
  int n, *xp, *xd, **x;
  cin >> n;
  xp = new int[2*n];
  xd = new int[4*n];
  x = new int*[n];
  for (int i = 0; i < n; ++i) x[i] = new int[n];
  step(n, x, xp, xd, 0);
  return 0;
}

