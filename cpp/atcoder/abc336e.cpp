#include <bits/stdc++.h>
using namespace std;
int n, ans;
int clac(int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i % clac(i) == 0) {
      cerr << i << '\n';
      ans++;
    }
  }
  cout << "==============================\n" << ans << '\n';
}
