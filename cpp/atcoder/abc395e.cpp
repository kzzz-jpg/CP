#include<bits/stdc++.h>
#define int long long
#include <queue>
using namespace std;
int n,m,c,hd[400500],to[800500],nxt[800500],w[800500],cnt=1;
int dis[800500];
bool vs[800500];
struct rd{
    int x,v;
    bool operator<(rd o) const{
        return v>o.v;
    }
    rd(int X,int V):x(X),v(V){}
};
void addE(int a,int b,int v){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    w[cnt]=v;
    hd[a]=cnt++;
}
signed main(){
    cin>>n>>m>>c;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        addE(x,y,1);
        addE(y+n,x+n,1);
    }
    for(int i=1;i<=n;i++) addE(i,i+n,c),addE(i+n,i,c);
    priority_queue<rd> pq;
    pq.push(rd(1,0));
    while(pq.size()){
        auto tp=pq.top();pq.pop();
        if(vs[tp.x]) continue;
        vs[tp.x]=1;
        dis[tp.x]=tp.v;
        for(int e=hd[tp.x];e;e=nxt[e]){
            if(!vs[to[e]]){
                pq.push(rd(to[e],tp.v+w[e]));
            }
        }
    }
    cout<<min(dis[n],dis[n+n])<<'\n';
}