#include<bits/stdc++.h>
using namespace std;
#define int long long
struct rd{
    int a,b,v;
    rd(int A=0,int B=0,int V=0):a(A),b(B),v(V){}
    bool operator<(rd o) const{
        return v<o.v;
    }
} r[1000500];
int n,m,k,cnt=0,u,v,w,ans;
int fa[200500],sz[200500];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void cb(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return;
    if(sz[a]>sz[b]) swap(a,b);
    fa[a]=b;
    sz[b]+=sz[a];
}
void init(){
    for(int i=0;i<=n;i++) fa[i]=i,sz[i]=1;
}
signed main(){
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=k;i++){
        cin>>u;
        r[++cnt]=rd(0,u,0);
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        r[++cnt]=rd(u,v,w);
    }
    sort(r+1,r+cnt+1);
    for(int i=1;i<=cnt;i++){
        if(find(r[i].a)==find(r[i].b)) continue;
        cb(r[i].a,r[i].b);
        ans+=r[i].v;
    }
    cout<<ans<<'\n';
}