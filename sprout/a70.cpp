#include <bits/stdc++.h>
#define DEBUG
using namespace std;
random_device rd;
mt19937 rg(rd());
int n;
double a[100], b[100], c[100];
double ans = 0, anst = 0, x = 0;
double getn(double t) {
  double ret = 0;
  for (int i = 1; i <= n; i++)
    ret = max(ret, a[i] * (x - b[i]) * (x - b[i]) + c[i]);
  return ret;
}
void sa() {
  double T = 20, low = 0.99612, ed = 1e-10;
  for (; T > ed; T *= low) {
    double dx = ((rg() % 30000 + rg() % 30000) - rg() % 60000) * T;
    x += dx;
    if (x > 400 || x < -100) {
      x -= dx;
      continue;
    }
    double nw = getn(x);
    if (nw < ans) {
      ans = nw, anst = x;
    } else if (exp((ans - nw) / T) < double(rg()) / rg.max())
      x -= dx;
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i] >> c[i];
  anst = 0;
  x = 0;
  ans = 0;
  ans = getn(anst);
  for (int i = 1; i < 350; i++)
    sa();
  if (anst > 300)
    cout << fixed << setprecision(16) << getn(300) << '\n';
  else if (anst < 0)
    cout << fixed << setprecision(16) << getn(0) << '\n';
  else
    cout << fixed << setprecision(16) << ans << '\n';
}
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
