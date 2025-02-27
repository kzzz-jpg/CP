#include <stdio.h>
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
int n,s[200010],r,x;
signed main(){
    n=nextint();
    for(register int i=1;i<=n;i++) {
        x=nextint();
        if(x<0) {
            if(r==0||s[r]!=-x){
                putc('l'),putc('o'),putc('s'),putc('e'),putc(' '),putc('l'),putc('i'),putc('g'),putc('h'),putc('t'),putc(' '),putc('l'),putc('i'),putc('g'),putc('h'),putc('t');
                flush();
                return 0;
            }else r--;
        }else s[++r]=x;
    }
    if(r) putc('l'),putc('o'),putc('s'),putc('e'),putc(' '),putc('l'),putc('i'),putc('g'),putc('h'),putc('t'),putc(' '),putc('l'),putc('i'),putc('g'),putc('h'),putc('t');
    else{
        putc('w');
        putc('e');
        putc('e');
        putc('d');
    }
    flush();
}