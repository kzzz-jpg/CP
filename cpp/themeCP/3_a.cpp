#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s >> s;
  int ans = 0;
  for (auto x : s)
    ans = max(ans, x - 'a' + 1);
  cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
