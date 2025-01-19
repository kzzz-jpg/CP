#include <bits/stdc++.h>
#define int long long
#define t8 __int128
using namespace std;
int n, m, p[200500];
pair<t8, t8> chk(t8 up) {
  t8 ret = 0, cst = 0, del;
  for (int i = 1; i <= n; i++) {
    del = 0;
    for (t8 j = 1e18; j; j >>= 1) {
      while (del + j <= up && (del + j) * (del + j) * p[i] <= up)
        del += j;
    }
    ret += del;
    cst += del * del * p[i];
  }
  cerr << (int)(up) << ' ' << (int)(ret) << ' ' << (int)(cst) << '\n';
  return {cst, ret};
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  t8 ans = 0;
  for (t8 j = 1e18; j; j >>= 1) {
    while (chk(ans + j).first <= m)
      ans += j;
  }
  cout << (int)chk(ans).second << '\n';
}
