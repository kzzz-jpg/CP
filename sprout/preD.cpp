#include <cmath>
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
inline int min(int a, int b) { return a < b ? a : b; }
int n, m;
unsigned long long sum = 0, ans = 8e18;
long long r[1010], c[1010];
bool chk(int x, int y) {
  bool a = 1, b = 1, C = 1, d = 1;
  for (int i = 1; i <= n; i++) {
    if (r[i] % x != 0)
      a = 0;
    if (r[i] % y != 0)
      C = 0;
  }
  for (int j = 1; j <= m; j++) {
    if (c[j] % x != 0)
      b = 0;
    if (c[j] % y != 0)
      d = 0;
  }
  return (a && d) || (b && C);
}
signed main() {
  n = nextint(), m = nextint();
  int x;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      x = nextint();
      sum += x;
      r[i] += x;
      c[j] += x;
    }
  }
  for (int i = 1; i <= sqrt(sum) + 5; i++) {
    if (sum % i == 0 && chk(i, sum / i)) {
      ans = min(ans, (sum / i + i) * 2);
    }
  }
  wrtn(ans);
  putc('\n');
  flush();
}
