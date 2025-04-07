#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n, x, ans;
void solve() {
  ans = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> x, pq.push(x);
  while (pq.size() > 1) {
    auto tp1 = pq.top();
    pq.pop();
    auto tp2 = pq.top();
    pq.pop();
    ans += tp1 + tp2;
    pq.push(tp1 + tp2);
  }
  cout << ans << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
