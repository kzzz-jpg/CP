#include <bits/stdc++.h>
using namespace std;
struct din {
  int x, y;
  bool operator<(din o) const { return y > o.y; }
} a[200500];
int n, ans;
void solve() {
  ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].x >> a[i].y;
  sort(a + 1, a + 1 + n);
  int nw = 0;
  for (int i = 1; i <= n; i++) {
    nw += a[i].x;
    ans = max(ans, a[i].y + nw);
  }
  cout << ans << '\n';
};
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
