#include <iostream>
#include <vector>

using namespace std;

int getIndex(int *x, vector<int>& tailIndices, int l, int r, int key) {
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (x[tailIndices[m]] >= key) r = m; else l = m;
  }
  return r;
}

int main(int argc, char *argv[]) {
  int n, *x;
  cin >> n;
  x = new int[n];
  for (int i = 0; i < n; ++i) cin >> x[i];

  vector<int> tailIndices(n, 0);
  vector<int> prevIndices(n, -1);
  vector<int> res;

  int len = 1;
  for (int i = 1; i < n; ++i) {
    if (x[i] < x[tailIndices[0]]) {
      tailIndices[0] = i;
    } else if (x[i] > x[tailIndices[len - 1]]) {
      prevIndices[i] = tailIndices[len - 1];
      tailIndices[len++] = i;
    } else {
      int pos = getIndex(x, tailIndices, -1, len - 1, x[i]);
      prevIndices[i] = tailIndices[pos - 1];
      tailIndices[pos] = i;
    }
  }

  //  for (int i = 0; i < len; i++) cout << "tail[" << i << "]= " << tailIndices[i] << " "; cout << endl;
  //  for (int i = 0; i < len; i++) cout << "prev[" << i << "]= " << prevIndices[i] << " "; cout << endl;

  for (int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i]) res.insert(res.begin(), x[i]);

  for (int i = 0; i < res.size(); i++) cout << res[i] << " "; cout << endl;

  cout << "LIS size " << len << endl;

  return 0;
}

