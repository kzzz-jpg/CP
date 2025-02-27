#include<stdio.h>
#define putc putcr
#define max(x,y) x>y?x:y
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
static inline void wrtn(long long x) {
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
int a[200050];
long long ans;
int l[200050],s[200050],n,sr;
signed main(){
    n=nextint();
    for(int i=1;i<=n;i++){
        a[i]=nextint();
        while(sr&&a[s[sr]]>=a[i]) --sr;
        l[i]=s[sr];
        s[++sr]=i;
    }
    sr=0;
    s[0]=n+1;
    for(int i=n;i;i--){
        while(sr&&a[s[sr]]>=a[i]) --sr;
        ans=max(ans,((long long)(s[sr]-l[i]-1))*a[i]);
        s[++sr]=i;
    }
    wrtn(ans);
    putc('\n');
    flush();
}