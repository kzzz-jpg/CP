#include<cstdio>
#include<cstring>
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
int a[101][100010];
int l[101],r[101],n,q;
signed main(){
    n=nextint(),q=nextint();
    for(int i=1;i<=n;l[i++]=1);
    char op;
    int x,y;
    while(q--){
        op=readchar();
        //putc(op);
        //putc('\n');
        if(op=='A'){
            readchar(),readchar();
            x=nextint(),y=nextint();
            a[x][++r[x]]=y;
        }else if(op=='L'){
            readchar(),readchar(),readchar(),readchar();
            x=nextint();
            if(l[x]>r[x]){
                putc('q'),putc('u'),putc('e'),putc('u'),putc('e'),putc(' '),wrtn(x),putc(' '),putc('i'),putc('s'),putc(' '),putc('e'),putc('m'),putc('p'),putc('t'),putc('y'),putc('!'),putc('\n');
            }else ++l[x];
        }else{
            readchar(),readchar(),readchar();
            x=nextint(),y=nextint();
            memmove(a[y]+r[y]+1,a[x]+l[x],(r[x]-l[x]+1)*sizeof(int));
            r[y]+=r[x]-l[x]+1;
            l[x]=(r[x]=0)+1;
        }
    }
    for(int i=1;i<=n;i++){
        putc('q'),putc('u'),putc('e'),putc('u'),putc('e'),putc(' '),wrtn(i),putc(':');
        if(l[i]>r[i]) putc(' '),putc('e'),putc('m'),putc('p'),putc('t'),putc('y');
        else while(l[i]<=r[i]) putc(' '),wrtn(a[i][l[i]++]);
        putc('\n');
    }
    flush();
}