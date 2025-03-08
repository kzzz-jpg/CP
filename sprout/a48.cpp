#include <bits/stdc++.h>
using namespace std;
int n, m, q, hd[200500], sz[200500], to[200500], nxt[200500], deg[200500];
int cnt = 1;
void addE(int a, int b) {
  nxt[cnt] = hd[a];
  to[cnt] = b;
  hd[a] = cnt++;
  deg[b] = 1;
}
void dfs(int x, int par) {
  sz[x] = 1;
  for (int e = hd[x]; e; e = nxt[e]) {
    if (to[e] != par) {
      dfs(to[e], x);
      sz[x] += sz[to[e]];
    }
  }
}
void solve() {
  /*
  freopen("in.in", "r", stdin);
  freopen("tmp", "w", stdout);
  */
  cin >> n >> m;
  int x, y;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    addE(x, y);
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0)
      addE(n + 1, i);
  }
  dfs(n + 1, n + 1);
  cin >> q;
  while (q--) {
    cin >> x;
    cout << sz[x] << '\n';
  }
  cnt = 1;
  for (int i = 1; i <= n + 1; i++)
    deg[i] = hd[i] = sz[i] = 0;
}
signed main() {
  /*
  freopen("in.in", "r", stdin);
  freopen("tmp", "w", stdout);
  */
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
