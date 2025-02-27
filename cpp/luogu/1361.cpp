//未完成
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,k,u,sum,s,t,ans;
int n,m;
int hd[200500],nxt[200500],to[200500],w[200500],dis[200500];
int cnt=2;
void addE(int x,int y,int v){
    nxt[cnt]=hd[x];
    to[cnt]=y;
    w[cnt]=v;
    hd[x]=cnt++;
}
bool bfs(){
    memset(dis,0,sizeof(dis));
    queue<int> q;
    q.push(s);dis[s]=1;
    while(q.size()){
        auto tp=q.front();q.pop();
        for(int e=hd[tp];e;e=nxt[e]){
            if(w[e]&&dis[to[e]]==0){
                dis[to[e]]=dis[tp]+1;
                q.push(to[e]);
            }
        }
    }
    return dis[t];
}
int dfs(int x,int flow){
    if(x==t) return flow;
    int ret=0;
    for(int e=hd[x];e;e=nxt[e]){
        if(w[e]&&dis[to[e]]==dis[x]+1){
            int tmp=dfs(to[e],min(flow,w[e]));
            ret+=tmp,flow-=tmp;
            w[e]-=tmp,w[e^1]+=tmp;
        }
    }
    if(ret==0) dis[x]=0;
    return ret;
}
signed main(){
    cin>>n;
    s=n+1;
    t=n+2;
    for(int i=1;i<=n;i++){
        cin>>a;
        sum+=a;
        addE(s,i,a);
        addE(i,s,0);
    }
    for(int i=1;i<=n;i++){
        cin>>a;
        sum+=a;
        addE(i,t,a);
        addE(t,i,0);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>k>>a>>b;
        addE(s,i+2+n,a);
        addE(n+2+i,s,0);
        addE(n+2+m+i,t,b);
        addE(t,n+2+m+i,0);
        for(int j=1;j<=k;j++){
            cin>>u;
            addE(n+2+i,u,2e18);
            addE(u,n+2+i,0);
            addE(u,n+m+2+i,2e18);
            addE(n+m+2+i,u,0);
        }
    }
    while(bfs()) ans+=dfs(s,2e18);
    cout<<sum<<' '<<ans<<' '<<(sum-ans)<<'\n';
}