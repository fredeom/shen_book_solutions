#include <iostream>

using namespace std;

void ksubsetprint(int n, int k, int *x, int i) {
  if (i == n || k == 0) {
    if (!k) {
      for (int z = 0; z < i; ++z) {
        if (x[z]) cout << z + 1 << " ";
      }
      cout << endl;
    }
    return;
  }
  x[i] = 1;
  ksubsetprint(n, k-1, x, i+1);
  x[i] = 0;
  ksubsetprint(n, k, x, i+1);
}

int main(int argc, char *argv[]) {
  int n, k, *x;
  cin >> n >> k;
  x = new int[n];
  ksubsetprint(n, k, x, 0);
  return 0;
}

