#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int cnt=1;
int hd[400500],nxt[800500],to[800500],w[800500];
void addE(int a,int b,int c){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    w[cnt]=c;
    hd[a]=cnt++;
}
int s[200500];
struct nd{
    int x,v;
    bool operator<(nd o) const{
        return v>o.v;
    }
    nd(int X=0,int V=0):x(X),v(V){}
};
int dis[400500];
bool vs[400500];
void dij(){
    priority_queue<nd> pq;
    pq.push(nd(1,0));
    while(pq.size()){
        auto tp=pq.top();pq.pop();
        if(vs[tp.x]) continue;
        vs[tp.x]=1;
        dis[tp.x]=tp.v;
        for(int e=hd[tp.x];e;e=nxt[e]){
            if(!vs[to[e]]){
                pq.push(nd(to[e],tp.v+w[e]));
            }
        }
    }
}
signed main(){
    cin>>n>>m>>k;
    int x,y,op;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>op;
        if(op){
            addE(x,y,1);
            addE(y,x,1);
        }else{
            addE(x+n,y+n,1);
            addE(y+n,x+n,1);
        }
    }
    for(int i=1;i<=k;i++) cin>>s[i],addE(s[i],s[i]+n,0),addE(s[i]+n,s[i],0);
    dij();
    if(!vs[n]&&!vs[n+n]) cout<<-1<<'\n';
    else if(!vs[n]) cout<<dis[n+n]<<'\n';
    else if(!vs[n+n]) cout<<dis[n]<<'\n';
    else cout<<min(dis[n],dis[n+n]);
}