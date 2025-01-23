#include <bits/stdc++.h>
using namespace std;
int l, r;
void solve() {
  cin >> l >> r;
  if (r == 1 && l == r)
    cout << 1 << '\n';
  else
    cout << r - l << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
