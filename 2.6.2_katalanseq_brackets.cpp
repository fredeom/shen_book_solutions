#include <iostream>
#include <string>
#include <vector>

using namespace std;

void draw(int n, int *x) {
  //for (int i = 0; i < n - 1; ++i) cout << x[2*i] << " " << x[2*i + 1] << " ";
  //cout << endl;
  char ch = 'a' - 1;
  char *s = new char[2*(n-1)];
  for (int i = 0; i < 2*(n - 1); ++i) if (x[i] > 0) s[i] = ++ch; else s[i] = '1';
  string res = "";
  vector<string> stack;
  for (int i = 0; i < 2*(n - 1); ++i) {
    if (s[i] == '1') {
      string s1 = stack.back(); stack.pop_back();
      string s2 = stack.back(); stack.pop_back();
      stack.push_back('(' + s2 + s1 + ')');
    } else {
      stack.push_back(string("") + s[i]);
    }
  }
  for (vector<string>::iterator it = stack.begin(); it != stack.end(); ++it) {
    cout << *it;
  }
  cout << endl;
}

int main() {
  int n, *x, k, last = false, z, sum;
  cin >> n;
  x = new int[2*n];
  x[0] = 1;
  x[1] = 1;
  for (int i = 1; i < n - 1; ++i) {
    x[2*i] = -1;
    x[2*i + 1] = 1;
  }
  draw(n, x);
  while (!last) {
    k = 2*n - 3;
    while (x[k] == -1) k--;
    while (k > 0 && x[k] == 1) k--;
    if (k == 0) last = true; else {
      last = false;
      z = 0; sum = 1;
      while (z != k) sum += x[++z];
      x[k] = 1; sum += 2;
      while (k < 2*n - 3) {
        k++;
        if (sum > 1) x[k] = -1; else x[k] = 1;
        sum += x[k];
      }
      draw(n, x);
    }
  }
  return 0;
}

