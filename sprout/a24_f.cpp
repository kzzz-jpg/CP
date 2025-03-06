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
int r[1000010];
int h[101], b[101];
int n, m;
signed main() {
  n = nextint(), m = nextint();
  char op;
  int x, y;
  while (m--) {
    op = readchar();
    if (op == 'A') {
      readchar(), readchar();
      x = nextint(), y = nextint();
      if (b[x])
        b[x] = r[b[x]] = y;
      else
        h[x] = b[x] = y;
    } else if (op == 'L') {
      readchar(), readchar(), readchar(), readchar();
      x = nextint();
      if (h[x] == 0) {
        putc('q'), putc('u'), putc('e'), putc('u'), putc('e'), putc(' '),
            wrtn(x), putc(' '), putc('i'), putc('s'), putc(' '), putc('e'),
            putc('m'), putc('p'), putc('t'), putc('y'), putc('!'), putc('\n');
      } else if (h[x] == b[x]) {
        h[x] = b[x] = 0;
      } else {
        h[x] = r[h[x]];
      }
    } else {
      readchar(), readchar(), readchar();
      x = nextint(), y = nextint();
      if (h[y] == 0)
        h[y] = h[x];
      else
        r[b[y]] = h[x];
      if (b[x])
        b[y] = b[x];
      h[x] = b[x] = 0;
    }
    /*
    for (int i = 1; i <= n; i++) {
      putc('q'), putc('u'), putc('e'), putc('u'), putc('e'), putc(' '), wrtn(i),
          putc(':');
      if (h[i] == 0)
        putc(' '), putc('e'), putc('m'), putc('p'), putc('t'), putc('y');
      else {
        for (int j = h[i]; j; j = r[j]) {
          putc(' '), wrtn(j);
        }
        //  putc(' '), wrtn(b[i]);
      }
      putc('\n');
    }
    putc('\n');
    */
  }
  for (int i = 1; i <= n; i++) {
    putc('q'), putc('u'), putc('e'), putc('u'), putc('e'), putc(' '), wrtn(i),
        putc(':');
    if (h[i] == 0)
      putc(' '), putc('e'), putc('m'), putc('p'), putc('t'), putc('y');
    else {
      for (int j = h[i]; j; j = r[j]) {
        putc(' '), wrtn(j);
      }
    }
    putc('\n');
  }
  flush();
}
