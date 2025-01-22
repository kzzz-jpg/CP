#include <bits/stdc++.h>
using namespace std;
int n, m;
int x;
int a[200500], pos[200500];
signed main() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++)
    a[i] = pos[i] = i;
  while (m--) {
    cin >> x;
    pos[a[0]] = pos[x];
    swap(a[0], a[pos[x]]);
    pos[x] = 0;
  }
  for (int i = 1; i <= n; i++)
    cout << a[i] << '\n';
}
