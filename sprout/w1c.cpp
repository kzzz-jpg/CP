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
inline void wrtn(int x) {
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
struct Llist {
  int l, r;
} ls[200500];
int n, t, ft;
inline void print() {
  for (int i = ft;; i = ls[i].r) {
    wrtn(i), putc(" \n"[ls[i].r == 0]);
    if (ls[i].r == 0)
      break;
  }
}
signed main() {
  n = nextint();
  t = nextint();
  for (int i = 1; i <= n; i++) {
    ls[i].l = i - 1;
    ls[i].r = i + 1;
  }
  ls[n].r = 0;
  ls[1].l = 0;
  ft = 1;
  int L, R, op, x;
  while (t--) {
    op = nextint();
    x = nextint();
    if (op == 0) {
      ls[ls[x].r].l = ls[x].l;
      ls[ls[x].l].r = ls[x].r;
      if (ls[ls[x].r].l == 0)
        ft = ls[x].r;
    } else {
      if (x == ft)
        continue;
      L = ls[ls[x].l].l, R = ls[x].r;
      ls[L].r = x;
      ls[ls[x].l].r = R;
      ls[ls[x].l].l = x;
      ls[R].l = ls[x].l;
      ls[x].r = ls[x].l;
      ls[x].l = L;
      if (ls[x].l == 0)
        ft = x;
    }
    ls[0].l = ls[0].r = 0;
  }
  print();
  flush();
}
