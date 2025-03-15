#include <bits/stdc++.h>
#define DEBUG
using namespace std;
int n, m, s, t;
char g[105][105];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dis[105][105];
bool inR(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
void solve() {
  int ans = INT_MAX;
  memset(dis, 0, sizeof dis);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> g[i][j];
      if (g[i][j] == 'K')
        s = i, t = j;
    }
  }
  queue<pair<int, int>> q;
  q.push({s, t});
  dis[s][t] = 1;
  while (q.size()) {
    auto tp = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = tp.first + dir[i][0], ny = tp.second + dir[i][1];
      if (inR(nx, ny) && g[nx][ny] != '#' && dis[nx][ny] == 0) {
        dis[nx][ny] = dis[tp.first][tp.second] + 1;
        q.push({nx, ny});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (g[i][j] == '@' && dis[i][j])
        ans = min(ans, dis[i][j]);
    }
  }
  if (ans == INT_MAX)
    cout << "= =\"\n";
  else
    cout << --ans << '\n';
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
