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
const int P = 10, P2 = 4;
int a[2010], pre[4][2010];
int n, q;
signed main() {
  n = nextint(), q = nextint();
  for (int i = 1; i <= n; i++) {
    pre[1][i] = (nextint() % P);
    pre[2][i] = (pre[1][i] * pre[1][i] % P);
    pre[3][i] = (pre[1][i] * pre[2][i] % P);
    pre[0][i] = (pre[1][i] * pre[3][i] % P);
    pre[1][i] = (pre[1][i] + pre[1][i - 1]) % P;
    pre[2][i] = (pre[2][i] + pre[2][i - 1]) % P;
    pre[3][i] = (pre[3][i] + pre[3][i - 1]) % P;
    pre[0][i] = (pre[0][i] + pre[0][i - 1]) % P;
  }
  /*
    for (int i = 1; i <= n; i++)
      wrtn(pre[1][i]), putc(" \n"[i == n]);
    for (int i = 1; i <= n; i++)
      wrtn(pre[2][i]), putc(" \n"[i == n]);
    for (int i = 1; i <= n; i++)
      wrtn(pre[3][i]), putc(" \n"[i == n]);
    for (int i = 1; i <= n; i++)
      wrtn(pre[0][i]), putc(" \n"[i == n]);
    */
  int l, r, k;
  while (q--) {
    l = nextint(), r = nextint(), k = nextint();
    wrtn((pre[k % P2][r] - pre[k % P2][l - 1] + P) % P);
    putc('\n');
  }
  flush();
}

// 1 1 1 1
// 2 4 8 6
// 3 9 7 1
// 4 6 4 6
// 5 5 5 5
// 6 6 6 6
// 7 9 3 1
// 8 4 2 6
// 9 1 9 1
// 0 0 0 0
