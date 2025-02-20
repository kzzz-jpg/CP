#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
  cin >> n;
  if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
    cout << 366 << '\n';
  } else {
    cout << 365 << '\n';
  }
}
