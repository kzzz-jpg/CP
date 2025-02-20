#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100][100];
char t[100][100];
bool chk(int a, int b) {
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[a + i - 1][b + j - 1] != t[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cin >> s[i][j];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++)
      cin >> t[i][j];
  }
  for (int a = 1; a <= n - m + 1; a++) {
    for (int b = 1; b <= n - m + 1; b++) {
      if (chk(a, b))
        return cout << a << ' ' << b << '\n', 0;
    }
  }
}
