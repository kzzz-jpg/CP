#include <bits/stdc++.h>
using namespace std;
int g[105][105];
int n, m, c, x, p[105];
bool check(int a, int b) {
  if (p[a] > p[b])
    return 0;
  for (int i = 1; i <= m; i++) {
    if (g[a][i] == 0 && g[b][i] == 1)
      return 0;
  }
  for (int i = 1; i <= m; i++) {
    if (g[a][i] == 1 && g[b][i] == 0)
      return 1;
  }
  return p[a] < p[b];
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> c;
    for (int j = 1; j <= c; j++) {
      cin >> x;
      g[i][x] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;
      if (check(i, j)) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
}
