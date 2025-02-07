#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
//#pragma GCC target("avx")
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
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
inline void output(int _x){
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
int n,rt=1,ans,mxdp;
int A[200500];
int fa[200500],cnt=1,deg[200500];
int nxt[400500],hd[200500],to[400500];
vector<int> v;
void addE(int a,int b){
  nxt[cnt]=hd[a];
  to[cnt]=b;
  hd[a]=cnt++;
}
int LIS(){
  vector<int> ret;
  for(auto x:v){
    auto it=lower_bound(ret.begin(),ret.end(),x);
    if(it==ret.end()) ret.push_back(x);
    else *it=x;
  }
  return (int)ret.size();
}
void dfs(int x,int par){
  v.push_back(A[x]);
  if(deg[x]==1) ans=max(ans,LIS());
  for(int e=hd[x];e;e=nxt[e])if(to[e]!=par) dfs(to[e],x);
  v.pop_back();
}
void dfs2(int x,int par,int deep){
  mxdp=max(mxdp,deep);
  for(int e=hd[x];e;e=nxt[e])if(to[e]!=par) dfs2(to[e],x,deep+1);
}
signed main(){
  n=nextint();
  for(int i=1;i<=n;i++) A[i]=nextint(),fa[i]=i;
  int x,y;
  for(int i=1;i<n;i++){
    x=nextint(),y=nextint();
    x++,y++;
    deg[x]++;
    deg[y]++;
    addE(x,y);
    addE(y,x);
    fa[y]=x;
  }
  bool flag=0;
  for(int i=1;i<=n;i++){
    if(deg[i]>2) flag=1;
  }
  while(rt!=fa[rt]) rt=fa[rt];
  if(flag&&n>1000){
    dfs2(rt,0,1);
    output(mxdp);
    return 0;
  }
  dfs(rt,0);
  output(ans);
}
