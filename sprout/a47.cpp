#include <bits/stdc++.h>
#define DEBUG
using namespace std;
int head, cnt;
int n, a[200500];
int tr[200500][3];
int add(int i, int x) {
  if (i == 0)
    tr[++cnt][2] = x, i = cnt;
  else if (x > tr[i][2])
    tr[i][1] = add(tr[i][1], x);
  else
    tr[i][0] = add(tr[i][0], x);
  return i;
}
void dfs(int id) {
  if (id == 0)
    return;
  dfs(tr[id][0]);
  dfs(tr[id][1]);
  cout << tr[id][2] << '\n';
}
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("tmp", "w", stdout);
  freopen("err", "w", stderr);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], head = add(head, a[i]);
  dfs(head);
}
