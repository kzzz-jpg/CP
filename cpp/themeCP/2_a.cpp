#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  int t1, t2, dv;
  cin >> t1 >> t2 >> dv;
  if (t1 > t2)
    swap(t1, t2);
  if (dv > t2)
    cout << (n - t2) << '\n';
  else if (dv < t1)
    cout << (t1 - 1) << '\n';
  else
    cout << (t2 - t1) / 2 << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
