#include<bits/stdc++.h>
using namespace std;
int hd[100500],nxt[200500],to[200500];
int a[100500],dep[100500],top[100500],id[100500],w[100500],fa[100500],sz[100500],son[100500];
int cnt=1,n,r,q,p;
int tr[400500],lz[400500];
void push(int l,int r,int id){
        if(l==r) return;
        int mid=l+r>>1;
        tr[id<<1]+=(mid-l+1)*lz[id];
        tr[id<<1|1]+=(r-(mid+1)+1)*lz[id];
}
void build(int l,int r,int id){
        if(l==r){
                tr[id]==w[l];
                return;
        }
        int mid=l+r>>1;
        build(l,mid,id<<1);
        build(mid+1,r,id<<1|1);
        tr[id]=tr[id<<1]+tr[id<<1|1];
}
int query(int l,int r,int L,int R,int id){
        if(R<l||L>r) return 0;
        if(l<r) push(id);
        if(L<=l&&r<=R) return tr[id];
        int mid=l+r>>1;
        return query(l,mid,L,R,id<<1)+query(mid+1,r,L,R,id<<1|1);
}
void update(int l,int r,int L,int R,int v,int id){
        if(L>r||R<l) return;
        if(l<r) push(id);
        if(L<=l&&r<=R) {
                lz[id]=v;
                tr[id]+=(r-l+1)*v;
        }
        int mid=l+r>>1;
        update(l,mid,L,R,v,id<<1);
        update(mid+1,r,L,R,v,id<<1|1);
}

void addE(int a,int b){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        hd[a]=cnt++;
}
void dfs(int x,int par,int dp){
        dep[x]=dp;
        fa[x]=par;
        sz[x]=1;
        int mx=-1;
        for(int e=hd[x];e;e=nxt[e]){
                if(to[e]==fa[x]) continue;
                dfs(to[e],x,dp+1);
                sz[x]+=sz[to[e]];
                if(sz[to[e]]>mx) son[x]=to[e],mx=sz[to[e]];
        }
}
void dfs2(int x,int topf){
        id[x]=++cnt;
        w[cnt]=a[x];
        top[x]=topf;
        if(!son[x]) return;
        dfs2(son[x],topf);
        for(int e=hd[x];e;e=nxt[e]) if(to[e]!=fa[x]&&to[e]!=son[x]) dfs(to[e],to[e]);
}
signed main(){
        cin>>n>>q>>r>>p;
        for(int i=1;i<=n;i++) cin>>a[i];
        int x,y;
        for(int i=1;i<n;i++){
                cin>>x>>y;
                addE(x,y);
                addE(y,x);
        }
        cnt=0;
}
