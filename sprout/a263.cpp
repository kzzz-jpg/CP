#include <bits/stdc++.h>
#define DEBUG
using namespace std;
int n, hd[800500], to[800500], nxt[800500], sz[800500], mx[800500];
int cnt = 1;
void addE(int a, int b) {
  nxt[cnt] = hd[a];
  to[cnt] = b;
  hd[a] = cnt++;
}
void dfs(int x, int par) {
  sz[x] = 1;
  for (int e = hd[x]; e; e = nxt[e]) {
    if (to[e] != par) {
      dfs(to[e], x);
      sz[x] += sz[to[e]];
      mx[x] = max(mx[x], sz[to[e]]);
    }
  }
  mx[x] = max(n - sz[x], mx[x]);
}
void solve() {
  cin >> n;
  int x, y;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    x++;
    y++;
    addE(x, y);
    addE(y, x);
  }
  dfs(1, 1);
  int ans = 0;
  mx[ans] = 1e9;
  for (int i = 1; i <= n; i++) {
    if (mx[ans] > mx[i])
      ans = i;
  }
  cout << ans - 1 << '\n';
  for (int i = 1; i <= n; i++)
    sz[i] = hd[i] = mx[i] = 0;
  cnt = 1;
}
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("tmp", "w", stdout);
#endif
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
