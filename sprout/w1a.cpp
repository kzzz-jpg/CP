#include <stdio.h>
#define re register
#define putc putcr
const int S = 1 << 20; // buffer size
char _buf[1<<20], *_p = _buf, *_q = _buf;
static inline char readchar() {
  if (_p == _q && (_q = (_p = _buf) + fread(_buf, 1, S, stdin)) == _buf)
    return EOF;
  return *_p++;
}
static inline int nextint() {
  re int x = 0, c = readchar(), neg = 0;
  while (('0' > c || c > '9') && c != '-' && c != EOF)
    c = readchar();
  if (c == '-')
    neg = 1, c = readchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + (c ^ '0'), c = readchar();
  if (neg)
    x = -x;
  return x;
}
char buffer[1 << 21];
char buf[15];
int p1 = -1;
const int p2 = (1 << 21) - 1;
static inline void flush() { fwrite(buffer, 1, p1 + 1, stdout), p1 = -1; }
static inline void putcr(const char x) {
  if (p1 == p2)
    flush();
  buffer[++p1] = x;
}
static inline void wrtn(int x) {
  re int len = -1;
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
short a[100010];
int n;
short q[100010], s[100010];
int ql, qr, sr;
static inline void solve() {
  ql = 1;
  qr = sr = 0;
  n = nextint();
  for (re int i = 1; i <= n; i++)
    q[++qr] = i, a[i] = nextint();
  for (re int i = 1; i <= n; i++) {
    if (sr && s[sr] == a[i]) {
      sr--;
    } else {
      if (ql > qr) {
        putc('N');
        putc('o');
        putc('\n');
        return;
      }
      while (ql <= qr && (sr == 0 || s[sr] ^ a[i])) {
        s[++sr] = q[ql++];
      }
      if (sr == 0 || s[sr] ^ a[i]) {
        putc('N');
        putc('o');
        putc('\n');
        return;
      } else {
        sr--;
      }
    }
  }
  putc('Y');
  putc('e');
  putc('s');
  putc('\n');
}
signed main() {
  re int t = nextint();
  while (t--)
    solve();
  flush();
}