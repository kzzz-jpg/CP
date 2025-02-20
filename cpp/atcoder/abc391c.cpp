#include <bits/stdc++.h>
using namespace std;
int a[1000500], p[1000500];
int n, q, ans;
signed main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    a[i] = 1, p[i] = i;
  int op, x, y;
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      if (++a[y] == 2)
        ans++;
      if (--a[p[x]] == 1)
        ans--;
      p[x] = y;
    } else
      cout << ans << '\n';
  }
}
