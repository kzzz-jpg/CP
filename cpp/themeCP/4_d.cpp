#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[26], d[26];
string s, t;
void solve() {
  for (int i = 0; i < 26; i++)
    d[i] = c[i] = 0;
  cin >> n >> k >> s >> t;
  for (auto x : s)
    c[x - 'a']++;
  for (auto x : t)
    d[x - 'a']++;
  for (int i = 0; i < 26; i++)
    if (c[i] != d[i])
      return cout << "no\n", void();
  for (int i = 0; i < n; i++) {
    if (i + k >= n && i - k < 0 && s[i] != t[i])
      return cout << "no\n", void();
  }
  cout << "yes\n";
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
