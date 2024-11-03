#include<bits/stdc++.h>
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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
inline void output(int _x){
    if(!_x) putchar('0');
    char _buff[20]; int _f = 0;
    if(_x<0){
        putchar('-');
        _x=-_x;
    }
    while(_x > 0)
    {
        _buff[_f++] = _x%10+'0';
        _x /= 10;
    }
    for(_f-=1; _f >= 0; _f--)
        putchar(_buff[_f]);
    putchar('\n');
}
const int MAXN=4e5+100;
struct node{
	int op;
	int x,y,k;
	int id;
	node(int O=0,int X=0,int Y=0,int K=0,int I=0):op(O),x(X),y(Y),k(K),id(I){}
} q[MAXN],lq[MAXN],rq[MAXN];
int ans[MAXN];

int fw[MAXN];
void upd(int x,int v){
	for(;x<MAXN;x+=x&(-x)) fw[x]+=v;
}
int query(int x){
	int ret=0;
	for(;x>0;x-=x&(-x)) ret+=fw[x];
	return ret;
}

void solve(int vl,int vr,int ql,int qr){
	if(vl>vr||ql>qr) return;
	if(vl==vr){
		for(int i=ql;i<=qr;i++){
			if(q[i].op==2){
				ans[q[i].id]=vl;
			}
		}
		return ;
	}
	int mid=vl+vr>>1;

	int nl=0,nr=0;
	for(int i=ql;i<=qr;i++){
		if(q[i].op==1){
			if(q[i].x<=mid){
				upd(q[i].id,1);
				lq[++nl]=q[i];
			}else rq[++nr]=q[i];
		}else{
			int n=query(q[i].y)-query(q[i].x-1);
			if(q[i].k<=n){
				lq[++nl]=q[i];
			}else{
				q[i].k-=n;
				rq[++nr]=q[i];
			}
		}
	}
	for(int i=ql;i<=qr;i++){
		if(q[i].op==1){
			if(q[i].x<=mid){
				upd(q[i].id,-1);
			}
		}
	}
	for(int i=1;i<=nl;i++) q[i+ql-1]=lq[i];
	for(int i=1;i<=nr;i++) q[i+ql+nl-1]=rq[i];
	solve(vl,mid,ql,ql+nl-1);
	solve(mid+1,vr,ql+nl,qr);
}

int n,m;
signed main(){
    n=nextint(),m=nextint();
	int x;
	for(int i=1;i<=n;i++){
		x=nextint();
		q[i]=node(1,x,0,0,i);
	}
	int l,r,k;
	for(int i=1;i<=m;i++){
        l=nextint(),r=nextint(),k=nextint();
		q[i+n]=node(2,l,r,k,i);
	}
	solve(-1e9,1e9,1,n+m);
	for(int i=1;i<=m;i++) output(ans[i]);
}
