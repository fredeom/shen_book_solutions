#include <iostream>
#include <vector>

using namespace std;


int getIndex(int *arr, vector<int>& T, int l, int r, int key) {
  while (r-l > 1) {
    int m = (l + r) / 2;
    if (arr[T[m]] >= key) r = m; else l = m;
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
  vector<int> result;

  int len = 1;

  for (int i = 1; i < n; i++) {
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

  for (int z = tailIndices[len - 1]; z >= 0; z = prevIndices[z]) {
    result.insert(result.begin(), x[z]);
  }

  for (int z = 0; z < result.size(); ++z) {
    cout << result[z] << " ";
  }
  cout << endl;

  cout << "LIS size " << len << endl;

  return 0;
}


/*

10
1 4 5 8 2 3 9 5 3 4
1 2 3 9 9

0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15

0 0 [0]
1 1 [0 8]
2 1 [0 4]
3 1 [0 4 12]


0
0 1
0 1 3
0 1 3 7
0 2 6 9 11
0 2 6 9 11 15

*/

