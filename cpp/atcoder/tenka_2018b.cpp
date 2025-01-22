#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2];
int k;
int nw = 0;
signed main() {
  cin >> a[0] >> a[1] >> k;
  for (int i = 0; i < k; i++) {
    if (a[nw] & 1)
      a[nw]--;
    a[nw ^ 1] += a[nw] >> 1;
    a[nw] >>= 1;
    nw ^= 1;
  }
  cout << a[0] << ' ' << a[1] << '\n';
}
