#include<bits/stdc++.h>
using namespace std;
int fa[200500],sz[200500],ans=0;
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void cb(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    fa[a]=b;
    sz[b]+=a;
    ans--;
}
struct rd{
    int x,y;
    bool operator <(rd o) const{
        return x>o.x;
    }
} ls[200500];
int res[200500];
int cnt;
int nw=1;
int n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++) {
        cin>>ls[i].x>>ls[i].y;
        if(ls[i].x>ls[i].y) swap(ls[i].x,ls[i].y);
    }
    sort(ls+1,ls+1+m);
    for(int i=n;i;i--){
        ans++;
        for(;ls[nw].x>=i;nw++){
            cb(ls[nw].x,ls[nw].y);
        }
        res[++cnt]=ans;
    }
    for(cnt--;cnt;cnt--) cout<<res[cnt]<<'\n';
    cout<<0<<'\n';
}