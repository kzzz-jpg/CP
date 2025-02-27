#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,r,cnt=2,ans,hd[400500],to[400500],dis[400500],nxt[400500],w[400500],deg[400500];
void addE(int a,int b,int v){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    w[cnt]=v;
    hd[a]=cnt++;
}
bool bfs(){
    memset(dis,0,sizeof(dis));
    queue<int>q;
    q.push(r);dis[r]=1;
    while(q.size()){
        auto tp=q.front();q.pop();
        for(int e=hd[tp];e;e=nxt[e]){
            if(w[e]&&dis[to[e]]==0){
                dis[to[e]]=dis[tp]+1;
                q.push(to[e]);
            }
        }
    }
    return dis[n+1];
}
int dfs(int x,int flow){
    if(x==n+1) return flow;
    int sum=0;
    for(int e=hd[x];e;e=nxt[e]){
        if(w[e]&&dis[to[e]]==dis[x]+1){
            int tmp=dfs(to[e],min(flow,w[e]));
            sum+=tmp,flow-=tmp;
            w[e]-=tmp,w[e^1]+=tmp;
        }
    }
    if(sum==0) dis[x]=0;
    return sum;
}
signed main(){
    cin>>n>>r;
    for(int i=1,x,y,v;i<n;i++){
        cin>>x>>y>>v;
        deg[x]++,deg[y]++;
        addE(x,y,v);
        addE(y,x,v);
    }
    for(int i=1;i<=n;i++){
        if(deg[i]==1&&i!=r){
            addE(i,n+1,2e18);
            addE(n+1,i,0);
        }
    }
    while(bfs()) ans+=dfs(r,2e18);
    cout<<ans<<'\n';
}