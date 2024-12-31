#include<stdio.h>
#include<immintrin.h>
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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define ll long long
#define re register
char readchar() {
	const int S = 1<<20; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}
int nextint() {
	int x = 0, c = readchar(), neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
	if(c == '-') neg = true, c = readchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}
inline void output(ll _x){
    if(!_x) putchar('0');
    char _buff[20]; int _f = 0;
    while(_x > 0)
    {
        _buff[_f++] = _x%10+'0';
        _x /= 10;
    }
    for(_f-=1; _f >= 0; _f--)
        putchar(_buff[_f]);
    putchar('\n');
}

ll g[251][251];
int n,m,i,j,x,y;
ll ans=0,ret;
inline void max(){
    ret=ans>ret?ans:ret;
}
inline void init(){
    for(re int i=1;i<=n;i++) for(re int j=1;j<=m;j++) g[i][j]=g[i][j]+g[i-1][j]+g[i][j-1]-g[i-1][j-1];
}
/*
void init_mid(){
    for(re int i=1;i<=n;i++) for(re int j=1;j<=m;j++)g[i][j]+=g[i][j-1];
}*/
inline void query(){
    ret=g[x][y]-g[x][j-1]-g[i-1][y]+g[i-1][j-1];
}/*
void query_mid(re int x1,re int y1,re int x2,re int y2){
    ret=0;
    for(re int i=x1;i<=x2;i++){
        ret+=g[i][y2]-g[i][y1-1];
    }
}
void query_slow(re int x1,re int y1,re int x2,re int y2){
    ret=0;
    for(re int i=x1;i<=x2;i++){
        for(re int j=y1;j<=y2;j++) ret+=g[i][j];
    }
}*/
signed main(){
    n=nextint(),m=nextint();
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            g[i][j]=nextint();
        }
    }
    init();
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(x=i;x<=n;x++){
                for(y=j;y<=m;y++) query(),max(),ans=ret;
            }
        }
    }
    output(ans);
}