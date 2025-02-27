#include <stdio.h>
#include<string.h>
#define putc putcr
const int S = 1 << 20; // buffer size
char _buf[1<<20], *_p = _buf, *_q = _buf;
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
struct Link {
  int l, r;
} ls[1000010];
int n, q, ft, bk, sz, mx[1010],s[1000010],r;
short t[1000010];
static inline void solve() {
  memset(mx, 0x3f3f3f3f, sizeof mx);
  while(r) ls[s[r]].l=ls[s[r]].r=t[s[r]]=0,r--;
  ft = bk = sz = 0;
  n=nextint();
  static int x;
  for (int i = 1; i <= n; i++) {
    q=nextint();
    for (int j = 1; j <= q; j++) {
      x=nextint();
      t[x] = i;
      s[++r]=x;
    }
  }
  static char op;
  q=nextint();
  while (q--) {
    op=readchar();
    if (op == 'E') {
      readchar();readchar();readchar();readchar();readchar();readchar();
      x=nextint();
      s[++r]=x;
      if (sz == 0) {
        ft = x;
        bk = x;
        ls[x].l = ls[x].r = -1;
      } else if (t[x] && (mx[t[x]] ^ 0x3f3f3f3f)) {
        if (mx[t[x]] == bk) {
          ls[x].l = mx[t[x]];
          ls[x].r = -1;
          ls[mx[t[x]]].r = x;
          bk=x;
        } else {
          ls[ls[mx[t[x]]].r].l = x;
          ls[x].r = ls[mx[t[x]]].r;
          ls[x].l = mx[t[x]];
          ls[mx[t[x]]].r = x;
        }
      } else {
        ls[x].r = -1;
        ls[x].l = bk;
        ls[bk].r = x;
        bk = x;
      }
      sz++;
      if (t[x]!=0) mx[t[x]]=x;
    } else {
      readchar();readchar();readchar();readchar();readchar();readchar();readchar();
      wrtn(ft);
      putc('\n');
      if(sz==1||(t[ft]&&t[ls[ft].r]!=t[ft])) mx[t[ft]]=0x3f3f3f3f;
      if (sz > 1) {
        ft = ls[ft].r;
      } 
      sz--;
    }
  }
}
signed main() {
  int t = 1;
  t=nextint();
  if(1<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(1);
    putc('\n');
    solve();
  }
  if(2<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(2);
    putc('\n');
    solve();
  }
  if(3<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(3);
    putc('\n');
    solve();
  }
  if(4<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(4);
    putc('\n');
    solve();
  }
  if(5<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(5);
    putc('\n');
    solve();
  }
  if(6<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(6);
    putc('\n');
    solve();
  }
  if(7<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(7);
    putc('\n');
    solve();
  }
  if(8<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(8);
    putc('\n');
    solve();
  }
  if(9<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(9);
    putc('\n');
    solve();
  }
  if(10<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(10);
    putc('\n');
    solve();
  }
  if(11<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(11);
    putc('\n');
    solve();
  }
  if(12<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(12);
    putc('\n');
    solve();
  }
  if(13<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(13);
    putc('\n');
    solve();
  }
  if(14<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(14);
    putc('\n');
    solve();
  }
  if(15<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(15);
    putc('\n');
    solve();
  }
  if(16<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(16);
    putc('\n');
    solve();
  }
  if(17<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(17);
    putc('\n');
    solve();
  }
  if(18<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(18);
    putc('\n');
    solve();
  }
  if(19<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(19);
    putc('\n');
    solve();
  }
  if(20<=t){
    putc('L');
    putc('i');
    putc('n');
    putc('e');
    putc(' ');
    putc('#');
    wrtn(20);
    putc('\n');
    solve();
  }
  flush();
}
