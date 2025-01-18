#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k, tmp;
  map<int, int> mp;
  vector<pair<int, int>> v;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    mp[tmp]++;
  }
  for (auto [x, y] : mp) {
    v.push_back({y, x});
  }
  sort(v.begin(), v.end());
  int ans = v.size();
  for (auto [x, y] : v) {
    if (x <= k)
      ans--, k -= x;
    else
      break;
  }
  cout << max(ans, 1) << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
