#include <bits/stdc++.h>
using namespace std;
int n;
int a[200500], ans;
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    a[i] = min(a[i - 1] + 1, a[i]);
  for (int i = n; i >= 1; i--)
    a[i] = min(a[i + 1] + 1, a[i]);
  for (int i = 1; i <= n; i++) {
    ans = max(ans, min({a[i], i, n - i + 1}));
  }
  cout << ans << '\n';
}
