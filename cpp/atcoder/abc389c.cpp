#include <bits/stdc++.h>
#define int long long
using namespace std;
int q, op, k;
int fw[500500];
void upd(int x, int v) {
  for (; x <= 500100; x += x & -x)
    fw[x] += v;
}
int qry(int x) {
  int ret = 0;
  for (; x; x -= x & -x)
    ret += fw[x];
  return ret;
}
deque<pair<int, int>> s;
signed main() {
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> k;
      s.push_back({i, -k});
      upd(i, k);
    } else if (op == 2) {
      upd(s.front().first, s.front().second);
      s.pop_front();
    } else {
      cin >> k;
      cout << qry(s[k - 1].first - 1) << '\n';
    }
  }
}
