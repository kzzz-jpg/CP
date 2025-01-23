#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  int n;
  cin >> n;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      cout << n / i << ' ' << n - (n / i) << '\n';
      return;
    }
  }
  cout << 1 << ' ' << n - 1 << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
