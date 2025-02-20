#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, x, ans;
int hd[200500], to[200500], w[200500], nxt[200500], cnt = 2;
int dis[200500];
void addE(int a, int b, int c) {
  nxt[cnt] = hd[a];
  to[cnt] = b;
  w[cnt] = c;
  hd[a] = cnt++;
}
bool bfs() {
  memset(dis, 0, sizeof dis);
  queue<int> q;
  q.push(1);
  dis[1] = 1;
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
  return dis[n];
}
int dfs(int x, int flow) {
  // cerr << x << ' ' << flow << '\n';
  if (x == n) {
    return flow;
  }
  int sum = 0;
  for (int e = hd[x]; e; e = nxt[e]) {
    if (w[e] && dis[to[e]] == dis[x] + 1) {
      int t = dfs(to[e], min(flow, w[e]));
      w[e] -= t, w[e ^ 1] += t;
      sum += t, flow -= t;
    }
  }
  if (sum == 0)
    dis[x] = 0;
  return sum;
}
signed main() {
  cin >> n >> m >> x;
  int _x, _y, _v;
  for (int i = 1; i <= m; i++) {
    cin >> _x >> _y >> _v;
    addE(_x, _y, _v);
    addE(_y, _x, 0);
  }
  while (bfs()) {
    ans += dfs(1, 2e18);
  }
  if (ans == 0)
    cout << "Orz Ni Jinan Saint Cow!\n";
  else
    cout << ans << ' ' << ((x + ans - 1) / ans) << '\n';
}
