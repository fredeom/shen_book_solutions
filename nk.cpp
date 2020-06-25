#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
  int n, k, d;
  cin >> n >> k;
  cout << setprecision(k) << 1.0 / n << endl;
  cout << "0.";
  d = 10;
  while (k > 0) {
    while (d < n) { d *= 10; cout << "0"; k--;}
    cout << (d - d % n) / n; k--;
    d = d % n; d *= 10;
  }
  return 0;
}

