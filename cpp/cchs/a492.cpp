#include <bits/stdc++.h>
using namespace std;
string s[50050];
int n, ans;
map<string, set<int>> mp;
bool chk(string x) {
  if (x.size() & 1)
    return 0;
  int mid = x.size() >> 1;
  for (int i = 0; mid < x.size(); mid++, i++) {
    if (x[i] != x[mid])
      return 0;
  }
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    set<int> tmps;
    cin >> s[i];
    for (int j = 0; j < s[i].size(); j++) {
      if (chk(string(s[i].begin(), s[i].begin() + j)))
        for (auto x : mp[string(s[i].begin() + j, s[i].end())]) {
          tmps.insert(x);
        }
    }
    cerr << tmps.size() << '\n';
    ans += tmps.size();
    for (int j = 1; j < s[i].size(); j++) {
      for (int k = j + 1; k < s[i].size(); k++) {
        if (s[j] != s[k]) {
        }
      }
    }
    mp[s[i]].insert(i);
  }
  cout << ans << '\n';
}
