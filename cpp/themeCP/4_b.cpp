#include <bits/stdc++.h>
#define int long long
using namespace std;
int rev(int x) {
  int ret = 0;
  while (x) {
    ret = ret * 10 + x % 10;
    x /= 10;
  }
  return ret;
}
void solve() {
  int n;
  cin >> n;
  int tmp = rev(n);
  int a = 0, b = 0, l = 0, r = 0;
  while (tmp) {
    int cur = tmp % 10;
    tmp /= 10;
    if (cur & 1) {
      cur >>= 1;
      if (l > r)
        a = a * 10 + cur, l += cur, b = b * 10 + cur + 1, r += cur + 1;
      else
        a = a * 10 + cur + 1, l += cur + 1, b = b * 10 + cur, r += cur;
    } else
      a = a * 10 + cur / 2, l += cur / 2, r += cur / 2, b = b * 10 + cur / 2;
  }
  while (a + b != n)
    a *= 10, b *= 10;
  cout << a << ' ' << b << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
