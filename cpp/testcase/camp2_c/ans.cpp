#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, l, k;
int a[200500], b[200500], ans = 0;
signed main() {
  cin >> n >> l >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i], a[i] += a[i - 1];
  for (int i = 1; i <= n; i++)
    cin >> b[i], b[i] += b[i - 1];
  for (int i = 1; i + l - 1 <= n; i++) {
    if (a[i + l - 1] - a[i - 1] < k && b[i + l - 1] - b[i - 1] <= 0) {
      cout << "No Solution\n";
      return 0;
    } else if (a[i + l - 1] - a[i - 1] < k) {
      ans = max(ans,
                (-a[i + l - 1] + a[i - 1] + k + b[i + l - 1] - b[i - 1] - 1) /
                    (b[i + l - 1] - b[i - 1]));
    }
  }
  cout << ans << '\n';
}
