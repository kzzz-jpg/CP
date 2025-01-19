#include <bits/stdc++.h>
using namespace std;
int n, m, p[200500];
int dp[1050][1050], opt[1050][1050];
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
      for (int k = 1; k <= 1000; k++) {
        if (k * k * p[i] > j)
          break;
        if (dp[i - 1][j - k * k * p[i]] + k > dp[i][j])
          dp[i][j] = dp[i - 1][j - k * k * p[i]] + k, opt[i][j] = k;
      }
    }
  }
  cout << dp[n][m] << '\n';
  int nw = m;
  vector<int> v;
  for (int i = n; i >= 1; i--) {
    v.push_back(opt[i][nw]);
    nw = nw - opt[i][nw] * opt[i][nw] * p[i];
  }
  reverse(v.begin(), v.end());
  for (auto x : v)
    cout << x << ' ';
  cout << '\n';
}
