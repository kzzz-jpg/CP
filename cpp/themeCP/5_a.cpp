#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200500];
void solve() {
  cin >> n >> k;
  int l = 1, r = n;
  for (int i = 1; i <= n; i++) {
    if (i & 1)
      cout << r-- << " \n"[i == n];
    else
      cout << l++ << " \n"[i == n];
  }
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
