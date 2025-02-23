#include <cstdio>
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
struct st {
  int v, cnt;
} s[1000010];
int t, r, n;
long long ans;
inline void solve() {
  r = 0, ans = 0;
  n = nextint();
  for (int i = 1; i <= n; i++) {
    t = nextint();
    while (r && s[r].v < t)
      ans += s[r].cnt, r--;
    if (r && s[r].v == t) {
      ans += s[r].cnt;
      s[r].cnt++;
      if (r > 1)
        ans++;
    } else {
      if (r)
        ans++;
      s[++r] = {t, 1};
    }
  }
  wrtn(ans);
  putc('\n');
}
signed main() {
  int t = nextint();
  while (t--)
    solve();
  flush();
}
