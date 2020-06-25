#include <iostream>

using namespace std;

void subseqprint(int k, int *x, int i) {
  if (i == k) {
    for (int z = 0; z < k; z++)
      cout << x[z] << " ";
    cout << endl;
    return;
  }
  for (int z = 0; z <= i; z++) {
    x[i] = z + 1;
    subseqprint(k, x, i + 1);
  }
}

int main(int argc, char *argv[]) {
  int k, *x;
  cin >> k;
  x = new int[k];
  subseqprint(k, x, 0);
  return 0;
}

