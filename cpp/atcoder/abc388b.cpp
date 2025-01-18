#include <bits/stdc++.h>
using namespace std;
int n, d;
int a[200500], b[200500];
int ans;
signed int main(int argc, char *argv[]) {
  cin >> n >> d;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i];
  for (int i = 1; i <= d; i++) {
    ans = 0;
    for (int j = 1; j <= n; j++) {
      ans = max(ans, a[j] * (b[j] + i));
    }
    cout << ans << '\n';
  }
  return 0;
}
