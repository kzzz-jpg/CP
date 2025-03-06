#include <bits/stdc++.h>
#pragma GCC optimize(2)
#include <ios>
using namespace std;
bool a[100];
int n;
vector<int> s;
int mp[200];
vector<vector<int>> g(100);
void dfs(int x) {
  if (x == n) {
    for (auto ans : s)
      cout << ans << ' ';
    cout << '\n';
    exit(0);
  }
  for (auto tp : g[s.back()]) {
    if (!a[tp]) {
      a[tp] = 1;
      s.push_back(tp);
      dfs(x + 1);
      s.pop_back();
      a[tp] = 0;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= 12; i++)
    mp[i * i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;
      if (mp[i + j])
        g[i].push_back(j);
    }
  }
  for (int i = 1; i <= n; i++) {
    s.push_back(i);
    a[i] = 1;
    dfs(1);
    a[i] = 0;
    s.pop_back();
  }
  cout << 0 << '\n';
}
