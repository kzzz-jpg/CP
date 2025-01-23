#include <bits/stdc++.h>
#include <iostream>
#define int long long
using namespace std;
int n, l, r;
void solve() {
  cin >> n;
  l = 1, r = n - 2;
  if (n & 1) {
    if (n == 1)
      cout << 1 << '\n';
    else
      cout << -1 << '\n';
    return;
  }
  cout << n << ' ';
  for (int i = 2; i <= n; i++) {
    if ((i ^ 1) & 1)
      cout << l << ' ', l += 2;
    else
      cout << r << ' ', r -= 2;
  }
  cout << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
