#include<bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,inline,unroll-loops,no-stack-protector,fast-math")
#define int long long
using namespace std;
int n,m,cnt,mxcnt;
int hd[20050],nxt[400050],to[400050];
int in[20050],ot[20050],mx[20050];
bool vs[20050];
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
}
void addE(int a,int b){
    nxt[++cnt]=hd[a];
    to[cnt]=b;
    hd[a]=cnt;
}
void dfs(int x,int par){
    vector<int> arr;
    vs[x-n]=1;
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]!=par){
            if(arr.size()==0||ot[to[e]-n]>ot[arr[0]-n]){
                arr.clear();
                arr.push_back(to[e]);
            }else if(ot[to[e]-n]==ot[arr[0]-n]){
                arr.push_back(to[e]);
            }
        }
    }
    for(auto i:arr) if(!vs[i-n]) dfs(i,x);
}
void tps(int x,int par){
    int inc=0;
    vs[x]=1;
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]!=par){
            if(!vs[to[e]])
            tps(to[e],x);
            inc=max(inc,ot[to[e]-n]);
        }
    }
    ot[x-n]+=inc;
}
int aa,bb,cc;
signed main(){
    n=nextint(),m=nextint();
    for(int i=1;i<=n;i++) ot[i]=nextint();
    for(int i=0;i<m;i++){
        aa=nextint(),bb=nextint();
        addE(bb+n,aa+n);
        in[aa]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            tps(i+n,0);
            if(ot[i]>ot[mx[0]]) mxcnt=0,mx[mxcnt++]=i;
            else if(ot[i]==ot[mx[0]]) mx[mxcnt++]=i;
        }
    }
    for(int i=0;i<mxcnt;i++) dfs(mx[i]+n,0);
    output(ot[mx[0]]);putchar('\n');
    for(int i=1;i<=n;i++) {
        if(vs[i]) output(i),putchar(' ');
    }
}