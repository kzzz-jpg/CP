#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, ans, q, x;
int a[200500], b[200500];
void solve() {
  cin >> n >> k >> q;
  for (int i = 1; i <= k; i++)
    cin >> a[i];
  for (int i = 1; i <= k; i++)
    cin >> b[i];
  while (q--) {
    cin >> x;
    int pos = upper_bound(a, a + 1 + k, x) - 1 - a;
    ans = b[pos];
    if (a[pos] != x)
      ans += (x - a[pos]) * (b[pos + 1] - b[pos]) / (a[pos + 1] - a[pos]);
    cout << ans << ' ';
  }
  cout << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
