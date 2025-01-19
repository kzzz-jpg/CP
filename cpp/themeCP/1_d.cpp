#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  int clac = 1 + n, nw = 0;
  int ans = 0;
  if (n & 1)
    ans += clac >> 1;
  n >>= 1;
  while (n >= k) {
    if (n & 1)
      ans += clac * (1 << nw);
    nw++, n >>= 1;
  }
  cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
