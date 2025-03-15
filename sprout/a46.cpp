#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int tr[100500][3];
int cnt = 1;
int head;
int add(int i, int x) {
  if (i == 0) {
    tr[++cnt][2] = x;
    return cnt;
  } else if (tr[i][2] <= x) {
    tr[i][1] = add(tr[i][1], x);
  } else {
    tr[i][0] = add(tr[i][0], x);
  }
  return i;
}
int del(int i, int x) {
  if (tr[i][2] < x) {
    tr[i][1] = del(tr[i][1], x);
  } else if (tr[i][2] > x) {
    tr[i][0] = del(tr[i][0], x);
  } else {
    if (tr[i][0] == 0 && tr[i][1] == 0) {
      i = 0;
    } else if (tr[i][0] == 0 && tr[i][1] != 0) {
      i = tr[i][1];
    } else if (tr[i][1] == 0 && tr[i][0] != 0) {
      i = tr[i][0];
    } else {
      int tmp = tr[i][0];
      while (tr[tmp][1])
        tmp = tr[tmp][1];
      tr[i][2] = tr[tmp][2];
      tr[i][0] = del(tr[i][0], tr[tmp][2]);
    }
  }
  return i;
}
int pre(int i, int x) {
  if (i == 0)
    return INT_MIN;
  else if (tr[i][2] > x)
    return pre(tr[i][0], x);
  else
    return max(tr[i][2], pre(tr[i][1], x));
}
int nxt(int i, int x) {
  if (i == 0)
    return INT_MAX;
  else if (tr[i][2] < x)
    return nxt(tr[i][1], x);
  else
    return min(nxt(tr[i][0], x), tr[i][2]);
}
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  cin >> t;
  string op;
  int x;
  while (t--) {
    cin >> op >> x;
    if (op == "insert")
      head = add(head, x);
    else if (op == "delete")
      head = del(head, x);
    else {
      int pr = pre(head, x), nx = nxt(head, x);
      if (pr == nx || x - pr < nx - x) {
        cout << pr << '\n';
      } else if (x - pr > nx - x) {
        cout << nx << '\n';
      } else {
        cout << pr << ' ' << nx << '\n';
      }
    }
  }
}
