#include <bits/stdc++.h>
using namespace std;
int tr[200500][3];
int hd;
int cnt;
int n;
void insrt(int x) {
  if (hd == 0) {
    tr[1][2] = x;
    hd = 1;
    cnt++;
    return;
  }
  int nw = hd;
  while (tr[nw][0] || tr[nw][1]) {
    if (tr[nw][2] >= x)
      nw = tr[nw][0];
    else
      nw = tr[nw][1];
  }
  if (tr[nw][2] >= x)
    tr[nw][0] = ++cnt;
  else
    tr[nw][1] = ++cnt;
  tr[cnt][2] = x;
}
int pre(int x) {
  int nw = hd;
  int ret = -1e9;
  while (tr[nw][0] || tr[nw][1]) {
    if (tr[nw][2] <= x)
      nw = tr[nw][1], ret = max(ret, tr[nw][2]);
    else
      nw = tr[nw][0];
  }
  if (tr[nw][2] <= x)
    ret = max(ret, tr[nw][2]);
  return ret;
}
int nxt(int x) {
  int nw = hd;
  int ret = 1e9;
  while (tr[nw][0] || tr[nw][1]) {
    if (tr[nw][2] >= x)
      nw = tr[nw][0], ret = min(ret, tr[nw][2]);
    else
      nw = tr[nw][1];
  }
  if (tr[nw][2] >= x)
    ret = min(ret, tr[nw][2]);
  return ret;
}
void rm(int x) {
  int nw = hd;
  while (tr[nw][0] || tr[nw][1]) {
    if (tr[nw][2] == x)
      break;
    if (tr[nw][2] > x)
      nw = tr[nw][0];
    else
      nw = tr[nw][1];
  }
}
signed main() {
  cin >> n;
  string op;
  int x;
  while (n--) {
    cin >> op;
    if (op)
  }
}
