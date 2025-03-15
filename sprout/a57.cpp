#include <bits/stdc++.h>
#define int long long
#define DEBUG
using namespace std;
int h[4000500];
int cnt;
void push(int x) {
  h[++cnt] = x;
  int nw = cnt;
  while (nw != 1) {
    int fa = nw >> 1;
    if (h[nw] < h[fa])
      swap(h[nw], h[fa]);
    else
      return;
    nw = fa;
  }
}
void pop() {
  if (cnt) {
    cout << h[1] << '\n';
    swap(h[1], h[cnt--]);
    int nw = 1;
    while ((nw << 1) <= cnt) {
      int son = nw << 1;
      if (son + 1 <= cnt && h[son + 1] < h[nw])
        son++;
      if (h[son] < h[nw])
        swap(h[son], h[nw]);
      else
        return;
      nw = son;
    }
  } else
    cout << "empty!\n";
}
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
  freopen("tmp", "w", stderr);
#endif
  int t = 1;
  cin >> t;
  int op, x;
  while (t--) {
    cin >> op;
    if (op == 1)
      cin >> x, push(x);
    else
      pop();
  }
}
