#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int i, n;
int dfs(int x) {
  if (s[i] == '2') {
    int ret = 0;
    for (int k : {1, 2, 3, 4}) {
      i++;
      ret += dfs(x / 2);
    }
    return ret;
  } else
    return x * x * (s[i] - '0');
}
signed main() {
  cin >> s >> n;
  cout << dfs(n) << '\n';
}
