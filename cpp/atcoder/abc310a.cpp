#include <bits/stdc++.h>
using namespace std;
int p, q, n, x, mn = 1e9;
signed main() {
  cin >> n >> p >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    mn = min(mn, x);
  }
  cout << min(mn + q, p) << '\n';
}
