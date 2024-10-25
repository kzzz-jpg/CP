#include<bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,inline,unroll-loops,no-stack-protector,fast-math")
using namespace std;
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
int hd[200001],nxt[400001],to[400001];
int col[200001];
int vs[200001];
int n;
int cnt=1;
void addEg(int a,int b){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    hd[a]=cnt++;
}
int son[200001],sz[200001],ans[200001];
void dfs1(int x,int par){
    sz[x]=1;
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]!=par){
            dfs1(to[e],x);
            sz[x]+=sz[to[e]];
            if(sz[to[e]]>sz[son[x]]) son[x]=to[e];
        }
    }
}
int anscnt=0;
int dfs(int x,int par,bool ison,bool reans){
    if(reans){
        for(int e=hd[x];e;e=nxt[e]){
            if(to[e]!=par&&to[e]!=son[x]){
                dfs(to[e],x,0,1);
            }
        }
    }
    int tmp=0;
    if(son[x]){
        tmp+=dfs(son[x],x,1,reans);
    }
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]!=par&&to[e]!=son[x])
            tmp+=dfs(to[e],x,0,0);
    }
    if(!vs[col[x]]){
        tmp++;
    }
    vs[col[x]]++;
    if(reans) ans[x]=tmp;
    if(reans&&!ison) fill(vs,vs+200000,0);
    return tmp;
}
int a,b;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    n=nextint();
    for(int i=1;i<=n;i++) col[i]=nextint();
    for(int i=0;i<n-1;i++) a=nextint(),b=nextint(),addEg(a,b),addEg(b,a);
    vector<int> tmp(col+1,col+1+n);
    sort(tmp.begin(),tmp.end());
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
    for(int i=1;i<=n;i++) col[i]=lower_bound(tmp.begin(),tmp.end(),col[i])-tmp.begin()+1;
    dfs1(1,0);
    dfs(1,0,1,1);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}