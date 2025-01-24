#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[1000500][2];
char p[1000500];
int n, ans = 0;
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  for (int i = 1; i <= n; i++) {
    if (p[i] == '0') {
      dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
      dp[i][0] = 1;
    } else {
      dp[i][1] = dp[i - 1][0] + 1;
      dp[i][0] = dp[i - 1][1];
    }
    ans += dp[i][1];
  }
  cout << ans << '\n';
}
