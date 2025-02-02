#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int ans = 0;
  for (auto x : s)
    if (x == '1')
      ans++;
  cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
