#include <bits/stdc++.h>
using namespace std;
int n;
int a[500500];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] <= max(i - 1, n - i) * 2) {
      cout << "No\n";
      return;
    }
  }
  cout << "yes\n";
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
