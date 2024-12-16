#include<bits/stdc++.h>
using namespace std;
int n,deg[200500],dis[200500],a[200500];
void solve(){
    for(int i=1;i<=n;i++) deg[i]=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        dis[i]=1;
        cin>>a[i];
        deg[a[i]]++;
    }
    queue<int> q;
    int ans=0;
    for(int i=1;i<=n;i++) if(deg[i]==0) q.push(i),dis[i]=1;
    while(q.size()){
        auto tp=q.front();q.pop();
        //cerr<<tp<<' '<<dis[tp]<<'\n';
        ans=max(ans,dis[tp]);
        if(--deg[a[tp]]==0) q.push(a[tp]);
        //cerr<<":::"<<dis[a[tp]]<<' '<<dis[tp]<<'\n';
        dis[a[tp]]+=dis[tp];
        //cerr<<"==="<<a[tp]<<' '<<dis[a[tp]]<<'\n';
    }
    cout<<ans+2<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}