#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200500];
void solve() {
  for (int i = 1; i <= n; i++)
    a[i] = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n, greater<int>());
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i + 1]) {
      if (i + 3 <= n) {
        cout << a[i] << ' ' << a[i + 1] << ' ' << a[i + 2] << ' ' << a[i + 3]
             << '\n';
        return;
      }
      if (i + 2 <= n && i - 1 >= 1) {
        if (a[i] + a[i + 1] + a[i + 2] > a[i - 1]) {
          cout << a[i - 1] << ' ' << a[i] << ' ' << a[i + 1] << ' ' << a[i + 2]
               << '\n';
          return;
        }
      }
      if (i - 2 >= 1) {
        for (int j = 1; j <= i - 2; j++) {
          if (a[j] < a[j + 1] + a[i] + a[i + 1]) {
            cout << a[j] << ' ' << a[j + 1] << ' ' << a[i] << ' ' << a[i + 1]
                 << '\n';
            return;
          }
        }
      }
      break;
    }
  }
  cout << -1 << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
