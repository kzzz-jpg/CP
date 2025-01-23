#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, lv[200500], del;
int dfs(int x, map<int, bool> &mp) {
  if (mp[x])
    return 0;
  if (x <= 0)
    return 0;
  if (x == 1)
    return 1;
  mp[x] = 1;
  del = lower_bound(lv + 1, lv + 1 + 2023, x) - lv;
  return x * x + dfs(x - del, mp) + dfs(x - del + 1, mp);
}
void solve() {
  map<int, bool> mp;
  cin >> n;
  cout << dfs(n, mp) << '\n';
}
signed main() {
  int t = 1;
  for (int i = 1; i <= 2023; i++)
    lv[i] = lv[i - 1] + i;
  cin >> t;
  while (t--)
    solve();
}
