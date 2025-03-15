#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> bst;
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);

#endif //  DEBUG

  cin >> t;
  string op;
  int x;
  while (t--) {
    cin >> op >> x;
    if (op == "insert") {
      if (binary_search(bst.begin(), bst.end(), x))
        continue;
      bst.insert(lower_bound(bst.begin(), bst.end(), x), x);
    } else if (op == "delete") {
      bst.erase(lower_bound(bst.begin(), bst.end(), x));
    } else {
      int pos = upper_bound(bst.begin(), bst.end(), x) - bst.begin() - 1;
      int pos2 = lower_bound(bst.begin(), bst.end(), x) - bst.begin();
      if (pos >= 0 && (pos2 >= bst.size() || x - bst[pos] < bst[pos2] - x)) {
        cout << bst[pos] << '\n';
      } else if (x - bst[pos] > bst[pos2] - x || pos == pos2) {
        cout << bst[pos2] << '\n';
      } else {
        cout << bst[pos] << ' ' << bst[pos2] << '\n';
      }
    }
  }
}
