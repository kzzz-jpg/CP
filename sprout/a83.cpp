#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  string ans;
  int x;
  cin >> x;
  if (x == 1)
    return cout << 1 << '\n', void();
  for (int i = 9; i >= 2; i--) {
    while (x % i == 0) {
      ans.push_back('0' + i);
      x /= i;
    }
  }
  if (x != 1)
    cout << -1 << '\n';
  else {
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
