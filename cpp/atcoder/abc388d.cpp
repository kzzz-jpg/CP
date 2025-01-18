#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000500;
int n;
int fw[N];
int a[N];
void upd(int pos) {
  for (; pos < N; pos += pos & -pos)
    fw[pos]++;
}
int qry(int pos) {
  if (pos <= 0)
    return 0;
  int ret = 0;
  for (; pos; pos -= pos & -pos)
    ret += fw[pos];
  return ret;
}
int qry(int l, int r) { return qry(r) - qry(l - 1); }
signed main(signed argc, char *argv[]) {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    a[i] += qry(i - 1, N);
    upd(a[i]);
  }
  for (int i = 1; i <= n; i++)
    cout << max(0LL, a[i] - n + i) << " \n"[i == n];
  return 0;
}
