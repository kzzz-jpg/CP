#include<bits/stdc++.h>
using namespace std;
#define int long long
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
struct nd{
    int l,r,val;
} tr[26005000];
int a[1000001],tim[1000001];
int n,m,vi,loc,vali,op;
int cnt=0,tmcnt=0;
int build(int l,int r){
    int nw=++cnt;
    if(l==r) {
        tr[nw].val=a[l];
        return nw;
    }
    int mid=(l+r)>>1;
    tr[nw].l=build(l,mid);
    tr[nw].r=build(mid+1,r);
    return nw;
}
nd cop(int id){
    nd ret=tr[id];
    return ret;
}
int modify(int l,int r,int x,int v,int id){
    int nw=++cnt;
    tr[nw]=cop(id);
    if(l==r){
        tr[nw].val=v;
        return nw;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        tr[nw].l=modify(l,mid,x,v,tr[nw].l);
    }else{
        tr[nw].r=modify(mid+1,r,x,v,tr[nw].r);
    }
    return nw;
}
int query(int l,int r,int x,int id){
    if(l==r){
        return tr[id].val;
    }
    int mid=(l+r)>>1;
    if(x<=mid) return query(l,mid,x,tr[id].l);
    else return query(mid+1,r,x,tr[id].r);
}
signed main(){
    n=nextint(),m=nextint();
    for(int i=1;i<=n;i++) a[i]=nextint();
    tim[tmcnt++]=build(1,n);
    while(m--){
        vi=nextint(),op=nextint(),loc=nextint();
        if(op==1){
            vali=nextint();
            tim[tmcnt++]=modify(1,n,loc,vali,tim[vi]);
        }else{
            printf("%lld\n",query(1,n,loc,tim[vi]));
            tim[tmcnt++]=tim[vi];
        }
    }
}