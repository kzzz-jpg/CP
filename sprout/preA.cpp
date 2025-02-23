#include <bits/stdc++.h>
using namespace std;
inline char readchar() {
  const int S = 1 << 20; // buffer size
  static char buf[S], *p = buf, *q = buf;
  if (p == q && (q = (p = buf) + fread(buf, 1, S, stdin)) == buf)
    return EOF;
  return *p++;
}

inline int nextint() {
  int x = 0, c = readchar(), neg = false;
  while (('0' > c || c > '9') && c != '-' && c != EOF)
    c = readchar();
  if (c == '-')
    neg = true, c = readchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + (c ^ '0'), c = readchar();
  if (neg)
    x = -x;
  return x;
}
char buffer[1 << 21];
int p1 = -1;
const int p2 = (1 << 21) - 1;
inline void flush() { fwrite(buffer, 1, p1 + 1, stdout), p1 = -1; }
inline void putc(const char &x) {
  if (p1 == p2)
    flush();
  buffer[++p1] = x;
}
inline void wrtn(long long x) {
  static char buf[15];
  static int len = -1;
  if (x >= 0) {
    do {
      buf[++len] = x % 10 + 48, x /= 10;
    } while (x);
  } else {
    putc('-');
    do {
      buf[++len] = -(x % 10) + 48, x /= 10;
    } while (x);
  }
  while (len >= 0) {
    putc(buf[len]), --len;
  }
}
int n;
int a[1005], b[1050];
vector<pair<int, int>> Ans;
vector<set<int>> pos(1050);
signed main() {
  n = nextint();
  for (int i = 1; i <= n; i++)
    a[i] = nextint(), b[i] = a[i], pos[a[i]].insert(i);
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) {
      pos[a[i]].erase(pos[a[i]].find(i));
      continue;
    }
    auto it = pos[b[i]].begin();
    Ans.push_back({i, *it});
    pos[a[i]].erase(i);
    pos[a[i]].insert(*it);
    swap(a[i], a[*it]);
    pos[b[i]].erase(it);
  }
  wrtn(Ans.size());
  putc('\n');
  for (auto [x, y] : Ans) {
    wrtn(x);
    putc(' ');
    wrtn(y);
    putc('\n');
  }
  flush();
}
