#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, l, r, nw, ans, a[200500], tmp[200500], cnt;
void solve() {
  cin >> n >> l >> r;
  ans = 1e18;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  nw = cnt = 0;
  for (int i = 1; i <= r; i++)
    tmp[++cnt] = a[i];
  sort(tmp + 1, tmp + 1 + cnt);
  for (int i = 1; i <= r - l + 1; i++)
    nw += tmp[i];
  ans = min(ans, nw);
  nw = cnt = 0;
  for (int i = l; i <= n; i++)
    tmp[++cnt] = a[i];
  sort(tmp + 1, tmp + 1 + cnt);
  for (int i = 1; i <= r - l + 1; i++)
    nw += tmp[i];
  ans = min(ans, nw);
  cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
