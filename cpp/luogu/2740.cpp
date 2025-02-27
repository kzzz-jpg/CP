#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,dis[200500],hd[200500],to[200500],w[200500],nxt[200500],cnt=2;
void addE(int a,int b,int v){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    w[cnt]=v;
    hd[a]=cnt++;
}
bool bfs(){
    memset(dis,0,sizeof dis);
    queue<int> q;
    q.push(1);dis[1]=1;
    while(q.size()){
        auto tp=q.front();q.pop();
        for(int e=hd[tp];e;e=nxt[e]){
            if(w[e]&&dis[to[e]]==0){
                dis[to[e]]=dis[tp]+1;
                q.push(to[e]);
            }
        }
    }
    return dis[m];
}
int dfs(int x,int flow){
    if(x==m) return flow;
    int sum=0;
    for(int e=hd[x];e;e=nxt[e]){
        if(w[e]&&dis[to[e]]==dis[x]+1){
            int tmp=dfs(to[e],min(w[e],flow));
            sum+=tmp,flow-=tmp;
            w[e]-=tmp,w[e^1]+=tmp;
        }
    }
    if(sum==0) dis[x]=0;
    return sum;
}
signed main(){
    cin>>n>>m;
    int x,y,v;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>v;
        addE(x,y,v);
        addE(y,x,0);
    }
    while(bfs()) ans+=dfs(1,2e18);
    cout<<ans<<'\n';
}