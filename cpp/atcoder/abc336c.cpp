#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string bi[] = {"0", "2", "4", "6", "8"};
signed main() {
  cin >> n;
  if (n == 1)
    return cout << 0 << '\n', 0;
  n--;
  vector<int> ans;
  while (n) {
    ans.push_back(n % 5);
    n /= 5;
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << bi[ans[i]];
}
