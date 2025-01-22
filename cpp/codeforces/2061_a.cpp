#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x, l = 0, r = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x & 1)
      l++;
    else
      r++;
  }
  if (r == 0)
    cout << max(0, l - 1) << '\n';
  else
    cout << l + 1 << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
for (int i = 1; i <= n; i++)
