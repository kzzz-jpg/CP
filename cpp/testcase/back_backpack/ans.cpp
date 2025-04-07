//\frac{n+2}{2n+1}
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int P = 1e9 + 7;
int n, x;
int w[5050];
int a[5050];
int dp[5050];
void solve() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = x; j >= w[i]; j--) {
      dp[j] = (dp[j] + dp[j - w[i]]) % P;
    }
  }
  for (int i = 1; i <= n; i++) {
    memset(a, 0, sizeof(a));
    for (int j = 0; j <= x; j++) {
      if (j < w[i])
        a[j] = dp[j];
      else
        a[j] = (dp[j] - a[j - w[i]] + P) % P;
    }
    cout << a[x] % P << '\n';
  }
}
signed main() {
#ifdef DEBUG
  freopen("random_07.in", "r", stdin);
  freopen("tmp", "w", stdout);
#endif
  int t = 1;
  // cin>>t ;
  while (t--)
    solve();
}
