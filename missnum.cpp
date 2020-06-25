#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int n, x, s = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) { cin >> x; s += x; }
  cout << n*(n+1) / 2 - s << endl;
  return 0;
}

