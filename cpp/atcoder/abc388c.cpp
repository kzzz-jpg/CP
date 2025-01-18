#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[500500], ans;
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++)
    ans += upper_bound(a + 1, a + 1 + n, a[i] / 2) - a - 1;
  cout << ans << '\n';
}
