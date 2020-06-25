#include <iostream>

using namespace std;

void seqprint(int n, int k, int *x, int i) {
  if (i == k) {
    for (int z = 0; z < k; ++z) cout << x[z] << " ";
    cout << endl;
    return;
  }
  for (int z = 1; z <= n; ++z) {
    x[i] = z;
    seqprint(n, k, x, i + 1);
  }
}

int main(int argc, char *argv[]) {
  int n, k, *x;
  cin >> n >> k;
  x = new int[k];
  seqprint(n, k, x, 0);
  delete x;
  return 0;
}

