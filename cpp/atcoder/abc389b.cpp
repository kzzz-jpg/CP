#include <bits/stdc++.h>
#define int long long
using namespace std;
int x, dp[200500];
signed main() {
  cin >> x;
  dp[0] = 1;
  for (int i = 1; i < 100; i++) {
    dp[i] = i * dp[i - 1];
    if (dp[i] == x) {
      cout << i << '\n';
      return 0;
    }
  }
}
