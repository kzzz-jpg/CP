#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n; std::cin >> n;
  while (n--) {
    int16_t k; std::cin >> k; k--;
    std::cout << (k ? 32 - __builtin_clzl(k) : 1) << '\n';
  }
}