#include "bits/stdc++.h"
using namespace std;
#define int long long
int n,m;
int a[200500];
int hd[200500],to[200500],nxt[200500],cnt=1,deg[200500],mx[200500],ans=-1e18;
void addE(int a,int b){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    hd[a]=cnt++;
}
signed main(){
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        addE(x,y);
        deg[y]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx[i]=-1e18;
        if(deg[i]==0) q.push(i),mx[i]=0;;
    }
    while(q.size()){
        auto tp=q.front();q.pop();
        ans=max(ans,mx[tp]+a[tp]);
        for(int e=hd[tp];e;e=nxt[e]){
            mx[to[e]]=max(mx[to[e]],mx[tp]+a[tp]);
            if(--deg[to[e]]==0){
                q.push(to[e]);
            }
        }
    }
    cout<<ans<<'\n';
}