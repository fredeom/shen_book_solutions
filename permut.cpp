#include <iostream>

using namespace std;

void minuscycle(int n, int *x, int i) {
  int tmp = x[i];
  x[i] = - x[i];
  for (int z = 1; z <= n; ++z) cout << x[z] << " "; cout << endl;
  if (x[tmp] > 0) minuscycle(n, x, tmp);
}

int main(int argc, char *argv[]) {
  int n, *x, parity = 0;
  cin >> n;
  x = new int[n+1];
  for (int i=1; i<=n; ++i) cin >> x[i];

  for (int i=1; i<=n; ++i)
    if (x[i] > 0) {
      cout << "main cycle" << endl;
      minuscycle(n, x, i);
      parity = 1 - parity;
    }
  cout << (parity ? "Odd" : "Even") << endl;
  for (int i=1; i<=n; ++i) {
    if (x[i] < 0) {
      cout << "main cycle 2" << endl;
      int tmp = - x[i], j = i;
      while (x[tmp] < 0) {
        int tmp2 = -x[tmp];
        x[tmp] = j;
        j = tmp;
        tmp = tmp2;
      }
    }
  }
  for (int i=1; i<=n; ++i) cout << x[i] << " "; cout << endl;
  return 0;
}

