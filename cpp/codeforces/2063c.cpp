#include <bits/stdc++.h>
using namespace std;
int hd[400500], nxt[400500], to[400500];
int n, deg[200500], ans;
int cnt = 1, x, y;
void addE(int a, int b) {
  nxt[cnt] = hd[a];
  to[cnt] = b;
  hd[a] = cnt++;
}
void solve() {
  cnt = 1;
  for (int i = 1; i <= n; i++)
    hd[i] = deg[i] = 0;
  ans = 0;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    deg[x]++, deg[y]++;
    addE(x, y);
    addE(y, x);
  }
  multiset<int> s;
  for (int i = 1; i <= n; i++) {
    cerr << deg[i] << " \n"[i == n];
    s.insert(deg[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int e = hd[i]; e; e = nxt[e]) {
      s.erase(s.find(deg[to[e]]));
      s.insert(deg[to[e]] - 1);
    }
    s.erase(s.find(deg[i]));
    ans = max(ans, deg[i] + *prev(s.end()) - 1);
    s.insert(deg[i]);
    for (int e = hd[i]; e; e = nxt[e]) {
      s.erase(s.find(deg[to[e]] - 1));
      s.insert(deg[to[e]]);
    }
  }
  cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}

// 1 2 3 4
// 1 3 1 1
//
//
//
