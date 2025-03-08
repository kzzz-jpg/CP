#include <bits/stdc++.h>
#define DEBUG
using namespace std;
int n, a[200500];
int tr[200500][2];
int i;
void build(int id, int par) {
  // cerr << id << ' ' << a[id] << '\n';
  if (i + 1 <= n && a[i + 1] <= a[id]) {
    tr[id][0] = ++i;
    build(i, id);
  }
  if (i + 1 <= n && a[i + 1] >= a[id] && (par == -1 || a[i + 1] <= a[par])) {
    tr[id][1] = ++i;
    build(i, id);
  }
}
void dfs(int id) {
  if (id == 0)
    return;
  dfs(tr[id][0]);
  dfs(tr[id][1]);
  cout << a[id] << '\n';
}
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("tmp", "w", stdout);
  freopen("err", "w", stderr);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(i = 1, -1);
  dfs(1);
}
