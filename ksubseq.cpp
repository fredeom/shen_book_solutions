#include <iostream>

using namespace std;

void subseqprint(int k, int *x, int i) {
  if (i == k) {
    for (int z = 0; z < k; z++)
      if (x[z]) cout << z+1 << " ";
    cout << endl;
    return;
  }
  for (int z = 0; z < 2; z++) {
    x[i] = z;
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

