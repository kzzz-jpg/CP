#include "bits/stdc++.h"
using namespace std;
#define int long long
struct rd{
    int x,y,c;
    bool operator<(rd o)const{
        return c<o.c;
    }
} r[200500];
int fa[200500],sz[200500];
int n,m,k,ans,lt;
int w[200500];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void cb(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return;
    if(sz[a]>sz[b]) swap(a,b);
    fa[a]=b;
    sz[b]+=a;
    lt--;
}
signed main(){
    cin>>n>>m;
    lt=n;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) cin>>r[i].x>>r[i].y>>w[i],r[i].c=0;
    cin>>k;
    int x;
    for(int i=1;i<=k;i++){
        cin>>x;
        r[x].c=w[x];
    }
    sort(r+1,r+1+m);
    for(int i=1;i<=m;i++){
        if(find(r[i].x)==find(r[i].y)) continue;
        cb(r[i].x,r[i].y);
        ans+=r[i].c;
    }
    if(lt>1) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}