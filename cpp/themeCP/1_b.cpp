#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, a[200500];
void solve() {
  multiset<int> s;
  cin >> n;
  ans = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      if (s.size()) {
        ans += *prev(s.end());
        s.erase(prev(s.end()));
      }
    } else
      s.insert(a[i]);
  }
  cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
