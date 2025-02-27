#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,s,t,cnt=2,dis[200500],hd[200500],nxt[200500],to[200500],w[200500];
void addE(int a,int b,int v){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    w[cnt]=v;
    hd[a]=cnt++;
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
    cin>>n;
    s=3*n+1,t=3*n+2;
    for(int i=1;i<=n;i++){
        addE(i,t,2);
        addE(t,i,0);
    }
    int x,y;
    for(int i=1;i<=2*n;i++){
        addE(s,n+i,1);
        addE(n+i,s,0);
        cin>>x>>y;
        addE(n+i,x,1);
        addE(x,n+i,0);
        addE(n+i,y,1);
        addE(y,n+i,0);
    }
    while(bfs()) ans+=dfs(s,2e18);
    cout<<ans<<'\n';
}