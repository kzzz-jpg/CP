#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200500];
int dp[200500][2];
const int P = 998244353;
void solve() {
  for (int i = 1; i <= n; i++)
    dp[i][0] = dp[i][1] = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  dp[1][1] = 1;
  if (a[1] == 0)
    dp[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 2] + 1)
      dp[i][0] = (dp[i][0] + dp[i - 1][1]) % P;
    if (a[i] == a[i - 1])
      dp[i][0] = (dp[i][0] + dp[i - 1][0]) % P;
    dp[i][1] = dp[i - 1][0];
  }
  cout << (dp[n][0] + dp[n][1]) % P << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
