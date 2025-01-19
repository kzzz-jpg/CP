#include <bits/stdc++.h>
#define int long long
using namespace std;
int ls[26];
int mx[26];
int ans;
string s;
int clac(int x) {
  int ret = 0;
  while (x) {
    ret++;
    x >>= 1;
  }
  return ret;
}
void solve() {
  cin >> s;
  for (int i = 0; i < 26; i++)
    ls[i] = -1, mx[i] = 0;
  ans = 0x3f3f3f3f;
  for (int i = 0; i < s.size(); i++) {
    mx[s[i] - 'a'] = max(mx[s[i] - 'a'], clac(i - ls[s[i] - 'a'] - 1));
    ls[s[i] - 'a'] = i;
  }
  for (int i = 0; i < 26; i++) {
    if (ls[i] != -1)
      mx[i] = max(mx[i], clac((int)(s.size()) - ls[i] - 1));
  }
  for (int i = 0; i < 26; i++)
    if (mx[i])
      ans = min(ans, mx[i]);
  if (ans == 0x3f3f3f3f)
    cout << 0 << '\n';
  else
    cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
