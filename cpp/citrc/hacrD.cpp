#include<bits/stdc++.h>
#define int long long
using namespace std;
struct rd{
    int x,y,c;
    bool operator<(rd o)const{
        return c<o.c;
    }
    rd(int X,int Y,int C):x(X),y(Y),c(C){}
};
vector<rd> r;
int ans=0,n;
int x[20050],y[20050];
int fa[20050],sz[20050];
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
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            r.push_back(rd(i,j,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
        }
    }
    sort(r.begin(),r.end());
    for(auto [x,y,c]:r){
        if(find(x)==find(y)) continue;
        ans+=c;
        cb(x,y);
    }
    cout<<ans<<'\n';
}