#include <iostream>

using namespace std;

int main(int argc, char*argv[]) {
  int n, m, **a, *b, c, tmp, cinc;
  cin >> n >> m;
  a = new int*[n];
  for (int i = 0; i < n; ++i) {
    a[i] = new int[m];
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  }

  b = new int[n]; c = a[0][0]; cinc = true;
  for (int i = 0; i < n; ++i) b[i] = 0;
  while (cinc) {
    cinc = false;
    //cout << "cinc = " << cinc << endl;
    for (int i = 0; i < n; ++i) {
      //cout << "i = " << i << endl;
      while (b[i] < m && a[i][b[i]] < c) {
        b[i]++;
        //cout << "b[" << i << "] = " << b[i] << " after ++" << endl;
      }
      tmp = a[i][b[i]];
      if (tmp > c) {
        c = tmp;
        //cout << "c = " << c << endl;
        cinc = true;
        break;
      }
    }
  }
  cout << a[0][b[0]] << endl;
  return 0;
}

