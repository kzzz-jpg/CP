#include <stdio.h>
int t, l, op, n, r;
int q[100010];
#define putc putcr
const int S = 1 << 10; // buffer size
char _buf[1<<10], *_p = _buf, *_q = _buf;
static inline char readchar() {
  if (_p == _q && (_q = (_p = _buf) + fread(_buf, 1, S, stdin)) == _buf)
    return EOF;
  return *_p++;
}
static inline int nextint() {
  int x = 0, c = readchar(), neg = 0;
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
  int len = -1;
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
  t = nextint();
  l = 1, r = 0;
  while (t--) {
    op = nextint();
    if (op == 1) {
      n = nextint();
      q[++r] = n;
    } else {
      if (l <= r)
        wrtn(q[l++]), putc('\n');
      else {
        putc('e');
        putc('m');
        putc('p');
        putc('t');
        putc('y');
        putc('!');
        putc('\n');
      }
    }
  }
  flush();
}
