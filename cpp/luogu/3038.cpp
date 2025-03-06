#include <bits/stdc++.h>
using namespace std;
int hd[200500], to[200500], nxt[200500], w[200500], n, m, cnt = 1;
int sz[200500], son[200500], dep[200500], fa[200500], top[200500], idx[200500],
    idcnt;
int tr[800500], lz[800500];
void push(int l, int r, int id) {
  if (l == r)
    return;
  int mid = l + r >> 1;
  tr[id << 1] += (mid - l + 1) * lz[id];
  lz[id << 1] += lz[id];
  tr[id << 1 | 1] += (r - mid) * lz[id];
  lz[id << 1 | 1] += lz[id];
  lz[id] = 0;
}
void upd(int l, int r, int L, int R, int id) {
  if (l > R || r < L)
    return;
  push(l, r, id);
  if (L <= l && r <= R) {
    lz[id] += 1;
    tr[id] += r - l + 1;
    return;
  }
  int mid = l + r >> 1;
  upd(l, mid, L, R, id << 1);
  upd(mid + 1, r, L, R, id << 1 | 1);
  tr[id] = tr[id << 1] + tr[id << 1 | 1];
}
int query(int l, int r, int L, int R, int id) {
  if (l > R || r < L)
    return 0;
  push(l, r, id);
  if (L <= l && r <= R)
    return tr[id];
  int mid = l + r >> 1;
  return query(l, mid, L, R, id << 1) + query(mid + 1, r, L, R, id << 1 | 1);
}
void addE(int a, int b) {
  nxt[cnt] = hd[a];
  to[cnt] = b;
  hd[a] = cnt++;
}
void dfs1(int x, int par, int deep) {
  fa[x] = par;
  dep[x] = deep;
  sz[x] = 1;
  for (int e = hd[x]; e; e = nxt[e]) {
    if (to[e] != par) {
      dfs1(to[e], x, deep + 1);
      sz[x] += sz[to[e]];
      if (son[x] == 0 || sz[to[e]] > sz[son[x]])
        son[x] = to[e];
    }
  }
}
void dfs2(int x, int topf) {
  top[x] = topf;
  idx[x] = ++idcnt;
  if (son[x])
    dfs2(son[x], topf);
  for (int e = hd[x]; e; e = nxt[e]) {
    if (to[e] != son[x] && to[e] != fa[x]) {
      dfs2(to[e], to[e]);
    }
  }
}
signed main() {
  int x, y;
  char op;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    addE(x, y);
    addE(y, x);
  }
  dfs1(1, 1, 1);
  dfs2(1, 1);
  while (m--) {
    cin >> op >> x >> y;
    if (op == 'Q') {
      if (dep[x] < dep[y])
        swap(x, y);
      cout << query(1, n, idx[x], idx[x], 1) << '\n';
    } else {
      while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
          swap(x, y);
        upd(1, n, idx[top[x]], idx[x], 1);
        x = fa[top[x]];
      }
      if (dep[x] > dep[y])
        swap(x, y);
      upd(1, n, idx[x] + 1, idx[y], 1);
    }
  }
}
