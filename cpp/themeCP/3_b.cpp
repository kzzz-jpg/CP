#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n & 1)
    return cout << -1 << '\n', void();
  cout << 0 << ' ' << 0 << ' ' << n / 2 << '\n';
}
void test() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        if ((i ^ j) + (j ^ k) + (i ^ k) == n)
          return cout << i << ' ' << j << ' ' << k << '\n', void();
      }
    }
  }
  cout << -1 << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
