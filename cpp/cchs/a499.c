#include <stdio.h>
int n, a, m;
signed main() {
  scanf("%d%d", &n, &a);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m);
    if (m > a) {
      break;
    } else {
      a += m;
    }
  }
  printf("%d", a);
}
