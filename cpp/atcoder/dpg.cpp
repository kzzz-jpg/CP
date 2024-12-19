#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[100500],deg[100500];
int hd[100500],to[100500],nxt[100500];
int cnt=1;
int ans;
void addE(int a,int b){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        hd[a]=cnt++;
}
signed main(){
        cin>>n>>m;
        int x,y;
        for(int i=1;i<=m;i++) cin>>x>>y,addE(x,y),deg[y]++;
        queue<int> q;
        for(int i=1;i<=n;i++) if(deg[i]==0) q.push(i);
        while(q.size()){
                auto tp=q.front();q.pop();
                ans=max(ans,dp[tp]);
                for(int e=hd[tp];e;e=nxt[e]){
                        dp[to[e]]=max(dp[to[e]],dp[tp]+1);
                        if(--deg[to[e]]==0) q.push(to[e]);
                }
        }
        cout<<ans<<'\n';
}
