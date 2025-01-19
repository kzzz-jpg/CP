#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  int n, k, g;
  cin >> n >> k >> g;
  int ans = 0;
  k *= g;
  int avr = (1 + g) >> 1;
  if (avr == 1)
    ans = 0;
  else if (n <= k / (avr - 1)) {
    ans += (n - 1) * (avr - 1);
    k -= (n - 1) * (avr - 1);
    k %= g;
    if (k >= avr)
      ans -= (g - k);
    else
      ans += k;
  } else {
    ans = k;
  }
  cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
