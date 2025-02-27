#include<bits/stdc++.h>
using namespace std;
int n,r,ans;
vector<vector<int>> g;
queue<int> q;
int h[200500],deg[200500];
signed main(){
    cin>>n;
    g.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>deg[i];
        if(deg[i]==0) q.push(i);
        for(int j=1,x;j<=deg[i];j++){
            cin>>x;
            g[i].push_back(x);
        }
    }
    while(q.size()){
        auto tp=q.front();q.pop();
        cerr<<tp<<'\n';
        r=tp;
        ans+=h[tp];
        for(auto x:g[tp]){
            h[x]=max(h[x],h[tp]+1);
            //cerr<<d
            if(--deg[x]==0) q.push(x);
            cerr<<deg[x]<<'\n';
        }
    }
    cout<<r<<'\n'<<ans<<'\n';
}