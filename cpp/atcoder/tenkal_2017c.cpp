#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main() {
  cin >> n;
  for (int i = 1; i <= 3500; i++) {
    for (int j = 1; j <= 3500; j++) {
      if (i * j % n == 0) {
        int k = 4 * (i * j / n) - i - j;
        if (k > 0 && i * j % k == 0) {
          cout << i << ' ' << j << ' ' << (i * j / k) << '\n';
          return 0;
        }
      }
    }
  }
}
