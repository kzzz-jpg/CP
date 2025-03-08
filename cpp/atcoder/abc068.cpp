#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (__builtin_ctz(i) > __builtin_ctz(ans))
      ans = i;
  }
  cout << ans << '\n';
}
