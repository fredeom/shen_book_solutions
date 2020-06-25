#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[]) {
  int n, m, **x, **mlt, **mrt, **mlb, **mrb, mx;
  cin >> n >> m;
  x = new int*[n]; mlt = new int*[n]; mrt = new int*[n]; mlb = new int*[n]; mrb = new int*[n];
  for (int i=0; i<n; ++i) {
    x[i] = new int[n];
    mlt[i] = new int[n];
    mrt[i] = new int[n];
    mlb[i] = new int[n];
    mrb[i] = new int[n];
    for (int j=0; j<n; ++j) cin >> x[i][j];
  }


  for (int i = 0; i < (n+(n%m)) / m; ++i)
  for (int j = 0; j < (n+(n%m)) / m; ++j) {
    int inext = (i+1) * m, jnext = (j+1) * m;
    if (inext > n) inext = n; if (jnext > n) jnext = n;

    for (int i1 = i*m; i1 < inext; ++i1)
    for (int j1 = j*m; j1 < jnext; ++j1) {
      mlt[i1][j1] = x[i1][j1];
      if (i1 > i*m  && mlt[i1][j1] < mlt[i1-1][j1]) mlt[i1][j1] = mlt[i1-1][j1];
      if (j1 > j1*m && mlt[i1][j1] < mlt[i1][j1-1]) mlt[i1][j1] = mlt[i1-1][j1];
    }

    for (int i1 = i*m; i1 < inext; ++i1)
    for (int j1 = jnext - 1; j1 >= j*m; --j1) {
      mrt[i1][j1] = x[i1][j1];
      if (i1 > i*m && mrt[i1][j1] < mrt[i1-1][j1]) mrt[i1][j1] = mrt[i1-1][j1];
      if (j1 < jnext - 1 && mrt[i1][j1] < mrt[i1][j1+1]) mrt[i1][j1] = mrt[i1][j1+1];
    }

    for (int i1 = inext - 1; i1 >= i*m; --i1)
    for (int j1 = jnext - 1; j1 >= j*m; --j1) {
      mrb[i1][j1] = x[i1][j1];
      if (i1 < inext - 1 && mrb[i1][j1] < mrb[i1+1][j1]) mrb[i1][j1] = mrb[i1+1][j1];
      if (j1 < jnext - 1 && mrb[i1][j1] < mrb[i1][j1+1]) mrb[i1][j1] = mrb[i1][j1+1];
    }

    for (int i1 = inext - 1; i1 >= i*m; --i1)
    for (int j1 = j*m; j1 < jnext; ++j1)  {
      mlb[i1][j1] = x[i1][j1];
      if (i1 < jnext - 1 && mlb[i1][j1] < mlb[i1+1][j1]) mlb[i1][j1] = mlb[i1+1][j1];
      if (j1 > j*m && mlb[i1][j1] < mlb[i1][j1-1]) mlb[i1][j1] = mlb[i1][j1-1];
    }
  }

/*
  cout << endl << "mlt" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << mlt[i][j] << " ";
    cout << endl;
  }
  cout << endl << "mrt" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << mrt[i][j] << " ";
    cout << endl;
  }
  cout << endl << "mlb" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << mlb[i][j] << " ";
    cout << endl;
  }
  cout << endl << "mrb" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << mrb[i][j] << " ";
    cout << endl;
  }
  cout << endl << "result" << endl;
*/
  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < n - m + 1; j++) cout << max(max(mrb[i][j], mlb[i][j+m-1]),
                                                    max(mlt[i+m-1][j+m-1], mrt[i+m-1][j])) << " ";
    cout << endl;
  }
  return 0;
}

