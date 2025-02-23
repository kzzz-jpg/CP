#include <bits/stdc++.h>
using namespace std;
struct Link {
  int l, r;
} ls[1000500];
int n, q, ft, bk, sz, t[1000500], mx[1050];
void solve() {
  memset(mx, 0x3f3f3f3f, sizeof mx);
  memset(ls, 0, sizeof ls);
  memset(t, 0, sizeof t);
  ft = bk = sz = 0;
  scanf("%d", &n);
  int x;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &q);
    for (int j = 1; j <= q; j++) {
      scanf("%d", &x);
      t[x] = i;
    }
  }
  char op[10];
  scanf("%d", &q);
  while (q--) {
    memset(op, 0, sizeof op);
    scanf("%s", op);
    if (strcmp(op, "ENQUEUE") == 0) {
      scanf("%d", &x);
      if (sz == 0) {
        ft = x;
        bk = x;
        ls[x].l = ls[x].r = -1;
      } else if (t[x] && mx[t[x]] != 0x3f3f3f3f) {
        if (ls[mx[t[x]]].r == -1) {
          ls[x].l = mx[t[x]];
          ls[x].r = -1;
          ls[mx[t[x]]].r = x;
        } else {
          ls[ls[mx[t[x]]].r].l = x;
          ls[x].r = ls[mx[t[x]]].r;
          ls[x].l = mx[t[x]];
          ls[mx[t[x]]].r = x;
        }
      } else {
        ls[x].r = -1;
        ls[x].l = bk;
        ls[bk].r = x;
        bk = x;
      }
      sz++;
      if (t[x])
        mx[t[x]] = x;
    } else {
      printf("%d\n", ft);
      if (sz > 1) {
        ft = ls[ft].r;
      }
      sz--;
    }
  }
}
signed main() {
  int t = 1;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    printf("Line #%d\n", i);
    solve();
  }
}
