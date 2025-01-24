#include <bits/stdc++.h>
using namespace std;
int trie[200500][26];
bool vs[200500];
int cnt = 1;
int n;
int ans = 0;
string str;
void insert(string &s) {
  int nw = 0;
  for (int i = 0; i < s.size(); i++) {
    if (trie[nw][s[i] - 'a'])
      nw = trie[nw][s[i] - 'a'];
    else {
      trie[nw][s[i] - 'a'] = cnt++;
      nw = trie[nw][s[i] - 'a'];
    }
  }
  vs[nw] = 1;
}
bool query(string &s) {
  int nw = 0;
  for (int i = 0; i < s.size(); i++) {
    if (trie[nw][s[i] - 'a'] == 0)
      return 0;
    nw = trie[nw][s[i] - 'a'];
  }
  return vs[nw];
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> str;
    if (query(str)) {
      continue;
    }
    reverse(str.begin(), str.end());
    if (query(str)) {
      continue;
    }
    ans++;
    insert(str);
  }
  cout << ans << '\n';
}
