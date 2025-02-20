#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, cnt = 2, g[200][200], dis[2000500], to[2000500], nxt[2000500],
          w[2000500], hd[2000500], s, t, ans = 0;
void addE(int a, int b, int v) {
  nxt[cnt] = hd[a];
  to[cnt] = b;
  w[cnt] = v;
  hd[a] = cnt++;
}
bool inR(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
int h(int x, int y) { return (x - 1) * m + y; }
int ho(int x, int y) { return (x - 1) * m + y + n * m; }
bool bfs() {
  memset(dis, 0, sizeof dis);
  queue<int> q;
  q.push(s), dis[s] = 1;
  while (q.size()) {
    auto tp = q.front();
    q.pop();
    for (int e = hd[tp]; e; e = nxt[e]) {
      if (w[e] && dis[to[e]] == 0) {
        dis[to[e]] = dis[tp] + 1;
        q.push(to[e]);
      }
    }
  }
  return dis[t];
}
int dfs(int x, int flow) {
  if (x == t)
    return flow;
  int sum = 0;
  for (int e = hd[x]; e; e = nxt[e]) {
    if (w[e] && dis[to[e]] == dis[x] + 1) {
      int tmp = dfs(to[e], min(flow, w[e]));
      sum += tmp, flow -= tmp;
      w[e] -= tmp, w[e ^ 1] += tmp;
    }
  }
  if (sum == 0)
    dis[x] = 0;
  return sum;
}
signed main() {
  cin >> n >> m;
  s = 2 * n * m + 1, t = 2 * n * m + 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> g[i][j];
      if (g[i][j] == 0) {
        addE(s, h(i, j), 2e8);
        addE(h(i, j), s, 0);
        addE(h(i, j), ho(i, j), 2e8);
        addE(ho(i, j), h(i, j), 0);
      } else if (g[i][j] != -1) {
        addE(h(i, j), ho(i, j), g[i][j]);
        addE(ho(i, j), h(i, j), 0);
      }
      for (auto [dx, dy] :
           (vector<pair<int, int>>){{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
        int nx = i + dx, ny = j + dy;
        if (inR(nx, ny)) {
          addE(ho(i, j), h(nx, ny), 2e8);
          addE(h(nx, ny), ho(i, j), 0);
        }
      }
      if (i == 1 || i == n || j == 1 || j == m) {
        addE(ho(i, j), t, 2e8);
        addE(t, ho(i, j), 0);
      }
    }
  }
  while (bfs())
    ans += dfs(s, 2e9);
  cout << ans << '\n';
}
