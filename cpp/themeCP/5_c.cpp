#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, mx, flag, flag2;
int a[200500];
int c, d;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  flag = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] % 5 == 0) {
      flag = 0;
    }
  }
  if (flag == 0) {
    for (int i = 1; i <= n; i++) {
      if (a[i] % 10)
        a[i] += 5;
      if (i > 1 && a[i] != a[i - 1])
        return cout << "no\n", void();
    }
    cout << "yes\n";
    return;
  }
  c = d = 0;
  for (int i = 1; i <= n; i++) {
    while (a[i] % 10 != 2)
      a[i] += a[i] % 10;
    a[i] /= 10;
    if (a[i] & 1)
      c++;
    else
      d++;
  }
  // cerr << c << ' ' << d << '\n';
  if (c && d) {
    cout << "no\n";
    return;
  }
  cout << "yes\n";
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}

// 22 24 28 36 42
// 1 2
// 3 6
//
// 18 26 32 34 38 46
// 1 2 4 8 16 22
