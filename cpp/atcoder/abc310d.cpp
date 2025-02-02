#include <bits/stdc++.h>
using namespace std;
int n, t, m, cnt = 1, x, y;
int hd[200], to[200], nxt[200], tem[20];
void addE(int a, int b) {
  nxt[cnt] = hd[a];
  to[cnt] = b;
  hd[a] = cnt++;
}
void dfs(int x) {
  if (x > n) {
    for (int)
  }
  for (int i = 1; i <= t; i++) {
    tem[x] = i;
    dfs(x + 1);
    tem[x] = 0;
  }
}
signed main() {
  cin >> n >> t >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    addE(x, y);
    addE(y, x);
  }
}
