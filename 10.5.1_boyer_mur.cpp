#include <iostream>
#include <string>

int main() {
  int *p, s1len, s2len, last;
  std::string s1, s2;
  //freopen("10.5.1.in", "r", stdin);
  std::cin >> s1 >> s2;
  s1len = s1.length();
  s2len = s2.length();
  p = new int[256];
  for (int i = 0; i < s2len; ++i) {
    p[s2[i]] = i;
  }

  last = s2len - 1;
  int cnt = 0;
  while (last < s1len) {
    cnt++;
    if (s2[s2len - 1] != s1[last]) {
      last += s2len - 1 - p[s1[last]];
    } else {
      bool eq = true;
      for (int i = s2len - 1; i >= 0; i--)
        if (s2[i] != s1[last - (s2len - 1) + i]) {
          eq = false;
          break;
        }
      if (eq) {
        std::cout << "Found " << last - (s2len - 1) << std::endl;
        exit(0);
      }
      last++;
    }
  }
  std::cout << "Not found " << cnt << std::endl;
  return 0;
}

