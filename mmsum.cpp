#include <iostream>
#include <iomanip>

using namespace std;

void print(int n, int *a[]) {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) cout << setw(4) << a[i][j];
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  int n, m, **x, **s;
  cin >> n >> m;
  x = new int*[n+1]; s = new int*[n+1];
  for (int i = 0; i <= n; ++i) {
    x[i] = new int[n+1]; s[i] = new int[n+1];
    for (int j = 0; j <= n; ++j) if (!i || !j) x[i][j] = 0; else cin >> x[i][j];
  }

  for (int i = 1; i <= n; ++i)
  for (int j = 1; j <= n; ++j) 
    s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + x[i][j];

  for (int i = 1; i <= n - m + 1; ++i) {
    for (int j = 1; j <= n - m + 1; ++j)
      cout << s[i-1][j-1] + s[i + m-1][j + m-1] - s[i-1][j + m-1] - s[i + m-1][j - 1] << " ";
    cout << endl;
  }

  return 0;
}

