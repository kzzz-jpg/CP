#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[3010], pre[3010], ls[3010];
const int P = 998244353;
int n, m, f;
int sum(int x) {
  if (x - f < 0)
    return pre[x] % P;
  return (pre[x] - pre[x - f] + P) % P;
}
signed main() {
  cin >> n >> m >> f;
  ls[0] = 1;
  pre[0] = 1;
  for (int i = 1; i <= m; i++)
    pre[i] = pre[i - 1] + ls[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[j] = sum(j - 1);
      ls[j] = dp[j];
    }
    ls[0] = 0;
    pre[0] = 0;
    for (int j = 1; j <= m; j++)
      pre[j] = (ls[j] + pre[j - 1]) % P;
  }
  cout << dp[m] % P << '\n';
}
