#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, c, x, d, ans;
void solve() {
  cin >> n >> c >> d;
  set<int> s;
  ans = 8e18;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    s.insert(x);
  }
  int nw = n - s.size();
  nw *= c;
  while (s.size()) {
    ans = min(ans, (int)((*prev(s.end()) - (int)s.size()) * d + nw));
    s.erase(prev(s.end()));
    nw += c;
  }
  ans = min(nw + d, ans);
  cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
