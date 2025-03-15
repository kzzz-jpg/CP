#include <stdio.h>
#define DEBUG
#define putc putcr
#define swap(x, y) (x ^= y ^= x ^= y)
const int S = 1 << 20; // buffer size
char _buf[1 << 20], *_p = _buf, *_q = _buf;
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
int h, w;
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
char g[1050][1050];
int fa[1000500], sz[1000500], lt;
int find(int x) {
  if (fa[x] == x)
    return x;
  return fa[x] = find(fa[x]);
}
void cb(int a, int b) {
  a = find(a), b = find(b);
  if (a == b)
    return;
  if (sz[a] > sz[b])
    swap(a, b);
  fa[a] = b;
  sz[b] += sz[a];
  lt--;
}
bool inR(int x, int y) { return x >= 1 && x <= h && y >= 1 && y <= w; }
int ha(int x, int y) { return (x - 1) * w + y; }
void solve() {
  h = nextint(), w = nextint();
  lt = 0;
  for (int i = 1; i <= h * w; i++)
    fa[i] = i, sz[i] = 1;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      g[i][j] = readchar();
      while (g[i][j] != '.' && g[i][j] != '#')
        g[i][j] = readchar();
      if (g[i][j] == '.')
        lt++;
    }
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (g[i][j] == '#')
        continue;
      for (int d = 0; d < 4; d++) {
        int nx = i + dir[d][0], ny = j + dir[d][1];
        if (inR(nx, ny) && g[nx][ny] == '.') {
          cb(ha(i, j), ha(nx, ny));
        }
      }
    }
  }
  wrtn(lt);
  putc('\n');
}
signed main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
  freopen("tmp", "w", stdout);
#endif
  int t = 1;
  t = nextint();
  while (t--)
    solve();
  flush();
}
