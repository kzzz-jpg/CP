#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b;
int dp[20][10][2][2];
int dfs(int pos, int val, int len, int pre, int fr, int ld) {
  //  cerr << pos << ' ' << len << ' ' << pre << ' ' << fr << ' ' << ld << '\n';
  if (pos == 0)
    return ld ^ 1;
  if (dp[pos][pre][fr][ld] != -1 && (!ld) && (!fr))
    return dp[pos][pre][fr][ld];
  int res = fr ? (val / len) % 10 : 9;
  int ret = 0;
  for (int i = 0; i <= res; i++) {
    if (abs(i - pre) < 2)
      continue;
    if (i == 0 && ld)
      ret += dfs(pos - 1, val, len / 10, -10, 0, 1);
    else
      ret += dfs(pos - 1, val, len / 10, i, fr && (i == res), 0);
  }
  dp[pos][pre][fr][ld] = ret;
  return ret;
}
int clac(int x) {
  int len = 1, pos = 0, tmp = x;
  while (x)
    pos++, len *= 10, x /= 10;
  len /= 10;
  return dfs(pos, tmp, len, -10, 1, 1);
}
signed main() {
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 10; j++)
      for (int k : {0, 1})
        dp[i][j][k][0] = dp[i][j][k][1] = -1;
  scanf("%lld%lld", &a, &b);
  printf("%lld", clac(b) - clac(a - 1));
}
