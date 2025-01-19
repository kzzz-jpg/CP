#include <bits/stdc++.h>
using namespace std;
int n, c, d;
int a[200500];
void solve() {
  cin >> n;
  c = d = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] & 1)
      c++;
    else
      d++;
  }
  cout << min(c, d) << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
