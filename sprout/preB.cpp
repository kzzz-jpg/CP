#include <cstdio>
int a[1000500];
int lf[1000500], r[1000500];
int n;
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
signed main() {
  n = nextint();
  for (int i = 1; i <= n; i++) {
    a[i] = nextint();
  }
  int nw;
  for (int i = 3; i <= n; i++) {
    nw = i;
    if (a[i])
      while (nw - 2 >= 1 && a[nw - 1] == 1 && a[nw - 2] == 0) {
        lf[i]++;
        nw -= 2;
      }
  }
  for (int i = n - 2; i >= 1; i--) {
    nw = i;
    if (a[i])
      while (nw + 2 <= n && a[nw + 1] == 1 && a[nw + 2] == 0) {
        r[i]++;
        nw += 2;
      }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      wrtn(-1), putc(" \n"[i == n]);
    } else {
      if (lf[i] >= 1 || r[i] >= 1) {
        wrtn(max(lf[i], r[i])), putc(" \n"[i == n]);
      } else if ((i - 1 >= 1 && a[i - 1] == 0) ||
                 (i + 1 <= n && a[i + 1] == 0)) {
        wrtn(1);
        putc(" \n"[i == n]);
      } else {
        wrtn(0);
        putc(" \n"[i == n]);
      }
    }
  }
  flush();
}
