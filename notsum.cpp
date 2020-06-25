#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int n, *x, k, N;
  cin >> n;
  x = new int[n];
  for (int i = 0; i < n; i++) cin >> x[i];

  k = -1; N = 0;
  while (k < n-1 && x[k+1] <= N + 1) {
    k++;
    N += x[k];
  }
  if (k == n - 1 || x[k+1] > N + 1) cout << N + 1 << endl;

  delete x;
  return 0;
}

