#include <bits/stdc++.h>
#define DEBUG
using namespace std;
const double eps = 1e-7;
double a[2000], b[2000], c[2000];
int n;
inline double max(double x, double y) {
  if (x > y)
    return x;
  return y;
}
double chk(double x) {
  double ret = 0;
  for (int i = 1; i <= n; i++) {
    ret = max(ret, a[i] * (x - b[i]) * (x - b[i]) + c[i]);
  }
  return ret;
}
void solve() {
  cin >> n;
  double l = 0, r = 300;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i] >> c[i];
  while (r - l > eps) {
    double lm = l + (r - l) / 3.0, rm = r - (r - l) / 3.0;
    if (chk(lm) < chk(rm))
      r = rm;
    else
      l = lm;
  }
  cout << fixed << setprecision(7) << chk(l) << '\n';
}
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("tmp", "w", stdout);
  freopen("err", "w", stderr);
#endif
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
