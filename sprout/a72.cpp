#include <bits/stdc++.h>
#include <cassert>
#define int long long
using namespace std;
int n, q[5000500], cnt;
void solve() {
  cnt = 0;
  memset(q, 0, sizeof(q));
  cin >> n;
  int x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (cnt == 0)
      q[++cnt] = x;
    else {
      if (x == q[cnt])
        continue;
      if (x > q[cnt] && q[cnt] > q[cnt - 1])
        q[cnt] = x;
      else if (x < q[cnt] && q[cnt] < q[cnt - 1])
        q[cnt] = x;
      else
        q[++cnt] = x;
    }
  }
  if (q[cnt] < q[cnt - 1])
    cnt--;
  assert(cnt > 0);
  cout << cnt << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
