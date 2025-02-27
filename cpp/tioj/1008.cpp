#include<bits/stdc++.h>
#include <random>
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

using namespace std;
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
bitset<345025252> vs;
int n,t;
short a[5];
int fp(int x,int y){
    int ret=1;
    while(y){
        if(y&1) ret*=x;
        x*=x;
        y>>=1;
    }
    return ret;
}
struct nd{
    short a[5];
    int cnt;
    int hash(){
        int ret=0;
        for(int i=0;i<n;i++){
            ret+=a[i]*fp(51,i);
        }
        return ret;
    }
    nd(int b=0,int c=0,int d=0,int e=0,int f=0,int Cnt=0):cnt(Cnt){
        a[0]=b,a[1]=c,a[2]=d,a[3]=e,a[4]=f;
    }
};
//random_device rd;
//mt19937 rg(rd());
signed main(){
    n=nextint();
    for(int i=0;i<n;i++) a[i]=nextint();
    t=nextint();
    queue<nd> q;
    int tmp;
    q.push(nd(0,0,0,0,0,0));
    vs[q.front().hash()]=1;
    while(q.size()){
        auto tp=q.front();q.pop();
        if(tp.a[0]==t||tp.a[1]==t||tp.a[2]==t||tp.a[3]==t||tp.a[4]==t){
            wrtn(tp.cnt),putc('\n');
            flush();
            return 0;
        }

        tp.cnt++;
        //if(tp.cnt>50) if(rg()%4==0) continue;
        for(int i=0;i<n;i++){
            tmp=tp.a[i];
            tp.a[i]=0;
            if(!vs[tp.hash()]){
                vs[tp.hash()]=1;
                q.push(tp);
            }
            tp.a[i]=tmp;
        }
        for(int i=0;i<n;i++){
            tmp=tp.a[i];
            tp.a[i]=a[i];
            if(!vs[tp.hash()]){
                vs[tp.hash()]=1;
                q.push(tp);
            }
            tp.a[i]=tmp;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(tp.a[i]>a[j]-tp.a[j]){
                    tmp=a[j]-tp.a[j];
                    tp.a[i]-=tmp;
                    tp.a[j]+=tmp;
                    if(!vs[tp.hash()]){
                        vs[tp.hash()]=1;
                        q.push(tp);
                    }
                    tp.a[i]+=tmp;
                    tp.a[j]-=tmp;
                }else{
                    tmp=tp.a[i];
                    tp.a[j]+=tmp;
                    tp.a[i]-=tmp;
                    if(!vs[tp.hash()]){
                        vs[tp.hash()]=1;
                        q.push(tp);
                    }
                    tp.a[i]+=tmp;
                    tp.a[j]-=tmp;
                }
            }
        }
    }
    putc('-'),putc('1'),putc('\n');
    flush();
}