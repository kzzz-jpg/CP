#include<bits/stdc++.h>
#define int long long
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
        tr[id<<1]%=p;
        tr[id<<1|1]%=p;
        lz[id<<1]+=lz[id];
        lz[id<<1|1]+=lz[id];
        lz[id]=0;
}
void build(int l,int r,int id){
        if(l==r){
                tr[id]=w[l]%p;
                return;
        }
        int mid=l+r>>1;
        build(l,mid,id<<1);
        build(mid+1,r,id<<1|1);
        tr[id]=(tr[id<<1]+tr[id<<1|1])%p;
}
int query(int l,int r,int L,int R,int id){
        if(R<l||L>r) return 0;
        push(l,r,id);
        if(L<=l&&r<=R) return tr[id];
        int mid=l+r>>1;
        return query(l,mid,L,R,id<<1)+query(mid+1,r,L,R,id<<1|1);
}
void update(int l,int r,int L,int R,int v,int id){
        if(L>r||R<l) return;
        push(l,r,id);
        if(L<=l&&r<=R) {
                lz[id]=v;
                tr[id]+=(r-l+1)*v;
                tr[id]%=p;
                return;
        }
        int mid=l+r>>1;
        update(l,mid,L,R,v,id<<1);
        update(mid+1,r,L,R,v,id<<1|1);
        tr[id]=(tr[id<<1]+tr[id<<1|1])%p;
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
        for(int e=hd[x];e;e=nxt[e]) if(to[e]!=fa[x]&&to[e]!=son[x]) dfs2(to[e],to[e]);
}
int queryxy(int x,int y){
        int ret=0;
        while(top[x]!=top[y]){
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                ret+=query(1,n,id[top[x]],id[x],1);
                ret%=p;
                x=fa[top[x]];
        }
        if(dep[x]>dep[y]) swap(x,y);
        ret+=query(1,n,id[x],id[y],1);
        return ret%p;
}
int queryfa(int x){
        int ret=0;
        ret=query(1,n,id[x],id[x]+sz[x]-1,1);
        return ret%p;
}
void updxy(int x,int y,int v){
        while(top[x]!=top[y]){
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                update(1,n,id[top[x]],id[x],v,1);
                x=fa[top[x]];
        }
        if(dep[x]>dep[y]) swap(x,y);
        update(1,n,id[x],id[y],v,1);
}
void updfa(int x,int v){
        update(1,n,id[x],id[x]+sz[x]-1,v,1);
}
signed main(){
        ios_base::sync_with_stdio(0),cin.tie(0);
        cin>>n>>q>>r>>p;
        for(int i=1;i<=n;i++) cin>>a[i];
        int x,y;
        for(int i=1;i<n;i++){
                cin>>x>>y;
                addE(x,y);
                addE(y,x);
        }
        cnt=0;
        dfs(r,r,1);
        dfs2(r,r);
        build(1,n,1);
        int op,v;
        while(q--){
                cin>>op;
                if(op==1){
                        cin>>x>>y>>v;
                        updxy(x,y,v);
                }else if(op==2){
                        cin>>x>>y;
                        cout<<queryxy(x,y)<<'\n';
                }else if(op==3){
                        cin>>x>>v;
                        updfa(x,v);
                }else{
                        cin>>x;
                        cout<<queryfa(x)<<'\n';
                }
        }
        cnt=0;
}
