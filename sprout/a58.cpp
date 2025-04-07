#include <bits/stdc++.h>
using namespace std;
#define DEBUG
int a, b, c, d, m, s, t;
int chk(int T) {
  int ret = 0, tmp;
  for (int i = 0; i <= T; i++) {
    tmp = min(T - i, (((d * i) + m) / c)) * b +
          max(0, (T - i - (((d * i) + m) / c))) * a;
    ret = max(ret, tmp);
  }
  return ret;
}
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("tmp", "w", stdout);
  freopen("err", "w", stderr);
#endif
  cin >> a >> b >> c >> d >> m >> s >> t;
  int l = 0, r = t;
  while (l < r) {
    int mid = l + r >> 1;
    cerr << l << ' ' << r << ' ' << chk(mid) << '\n';
    if (chk(mid) >= s)
      r = mid;
    else
      l = mid + 1;
  }
  cerr << chk(t) << '\n';
  if (chk(t) < s)
    cout << "No\n" << chk(t) << '\n';
  else
    cout << "Yes\n" << l << '\n';
}
