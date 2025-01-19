#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    if (n == 3) {
      cout << "no\n";
      return;
    }
    cout << "yes\n";
    int a[2] = {n / 2 - 1, -n / 2};
    int nw = 0;
    for (int i = 1; i <= n; i++) {
      cout << a[nw] << ' ';
      nw ^= 1;
    }
    cout << '\n';
    return;
  }
  cout << "yes\n";
  int nw = 1;
  for (int i = 1; i <= n; i++) {
    cout << nw << ' ';
    nw = -nw;
  }
  cout << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
