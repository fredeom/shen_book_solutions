#include <iostream>
#include <string>

int main() {
  int *p, k;
  std::string s1, s2, s3;
  freopen("10.4.in", "r", stdin);
  std::cin >> s1 >> s2;
  std::cout << s1 << std::endl << s2 << std::endl;
  s3 = s2 + "\255" + s1;
  std::cout << s3 << std::endl;
  p = new int[s3.length()];
  p[0] = -1;
  for (int i = 1; i < s3.length(); ++i) {
    k = p[i - 1];
    while (k >= 0) {
      if (s3[k] == s3[i-1]) {
        p[i] = k + 1;
        if (p[i] == s2.length()) {
          std::cout << "Found " << i - s2.length() << std::endl;
          exit(0);
        }
        break;
      }
      k = p[k];
    }
  }
  return 0;
}

