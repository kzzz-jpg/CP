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
inline int max(int a, int b) { return a < b ? b : a; }
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
int a[1000500];
long long x, y, ans;
signed main() {
  n = nextint();
  for (int i = 1; i <= n; i++)
    a[i] = nextint();
  x = nextint(), y = nextint();
  for (int i = 1, r = 1; i <= n; i = r + 1, r = i) {
    while (r + 1 <= n && (a[r + 1] - a[r] + 1) * x + y <= 2 * (x + y)) {
      r++;
    }
    ans += (a[r] - a[i] + 1) * x + y;
  }
  wrtn(ans);
  putc('\n');
  flush();
}
