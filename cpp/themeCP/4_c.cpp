#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int hd[200500], nxt[200500], to[200500], sz[200500];
int cnt = 1;
void addE(int a, int b) {
  nxt[cnt] = hd[a];
  to[cnt] = b;
  hd[a] = cnt++;
}
int dfs(int x, int par) {
  sz[x] = 0;
  int mx = 0;
  for (int e = hd[x]; e; e = nxt[e]) {
    if (to[e] == par)
      continue;
    sz[x]++;
    mx = max(mx, dfs(to[e], x) + 1);
  }
  return mx;
}
void solve() {
  for (int i = 1; i <= n; i++)
    hd[i] = 0;
  cnt = 1;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    addE(x, y);
    addE(y, x);
  }
  for (int i = 1; i <= n; i++) {
    if (dfs(i, 0) == 2) {
      cout << sz[i] << ' ' << sz[to[hd[i]]] << '\n';
      return;
    }
  }
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
