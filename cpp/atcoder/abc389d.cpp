#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000500;
int r, ans, del;
int dp[N << 1];
signed main() {
  cin >> r;
  for (int i = -r; i < r; i++) {
    del = (int)((sqrt((r - (i + (double)0.5)) * (r + i + (double)0.5))) - 0.5) +
          (int)((sqrt((r - (i + (double)0.5)) * (r + i + (double)0.5))) + 0.5);
    dp[i + N] = del;
  }
  for (int i = -r - 10; i <= r + 10; i++) {
    ans += min(dp[i + N], dp[i + 1 + N]);
  }
  cout << ans << '\n';
}
