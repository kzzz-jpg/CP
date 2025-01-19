#include <bits/stdc++.h>
using namespace std;
void solve() {
  set<char> s;
  for (int i = 0; i < 4; i++) {
    char c;
    cin >> c;
    s.insert(c);
  }
  cout << s.size() - 1 << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
