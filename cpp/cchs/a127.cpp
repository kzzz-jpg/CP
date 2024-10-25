#include<iostream>
#pragma GCC optimize("Ofast,inline,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
struct nd{
    int l,r,v;
} tr[4200050];
int cnt=0;
int lflim[200010];
int build(int l,int r){
    int nw=++cnt;
    if(l==r){
        tr[nw].v=1;
        return nw;
    }
    int mid=(l+r)>>1;
    tr[nw].l=build(l,mid);
    tr[nw].r=build(mid+1,r);
    tr[nw].v=tr[tr[nw].l].v+tr[tr[nw].r].v;
    return nw;
}
int modify(int l,int r,int pos,int id){
    int nw=++cnt;
    tr[nw].l=tr[id].l,tr[nw].r=tr[id].r,tr[nw].v=tr[id].v;
    if(l==r){
        tr[nw].v=0;
        return nw;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) tr[nw].l=modify(l,mid,pos,tr[id].l);
    else tr[nw].r=modify(mid+1,r,pos,tr[id].r);
    tr[nw].v=tr[tr[nw].l].v+tr[tr[nw].r].v;
    return nw;
}
int query(int l,int r,int L,int R,int id){
    if(l>R||r<L)return 0;
    if(L<=l&&r<=R){
        return tr[id].v;
    }
    int mid=(l+r)>>1;
    if(L>mid) return query(mid+1,r,L,R,tr[id].r);
    else if(R<=mid) return query(l,mid,L,R,tr[id].l);
    return query(l,mid,L,R,tr[id].l)+query(mid+1,r,L,R,tr[id].r);
}
int n,q,ql,qr,k,a[200010],mx=0;
int hd[200010],nxt[200010],to[200010];
int lscnt=1;
inline void addEdge(int u,int v){
    nxt[lscnt]=hd[u];
    to[lscnt]=v;
    hd[u]=lscnt++;
}
signed main(){
    n=nextint(),q=nextint();
    for(int i=1;i<=n;i++) {
        a[i]=nextint();
        addEdge(a[i],i);
        mx=std::max(mx,a[i]);
    }
    lflim[mx+1]=build(1,n);
    for(int i=mx;i>=0;i--){
        lflim[i]=lflim[i+1];
        for(int e=hd[i];e;e=nxt[e]){
            lflim[i]=modify(1,n,to[e],lflim[i]);
        }
    }
    while(q--){
        ql=nextint(),qr=nextint(),k=nextint();
        k=std::min(k,mx);
        output(query(1,n,ql,qr,lflim[k+1]));
    }
}