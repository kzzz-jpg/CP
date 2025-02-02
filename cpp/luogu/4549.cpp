#include "bits/stdc++.h"
using namespace std;
int n, a[200500], ans;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    ans = gcd(a[i], ans);
  cout << abs(ans) << '\n';
}
