#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
int hd[200500],nxt[400500],to[400500],w[400500];
int cnt=1,n,m;
int h[200500];
void addE(int a,int b,int v){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        w[cnt]=v;
        hd[a]=cnt++;
}
struct nd{
        int x,v;
        bool operator<(nd o)const{
                return v>o.v;
        }
        nd(int xx,int vv):x(xx),v(vv){}
};
bool vs[200500];
int dis[200500];
int SPFA(){
        for(int i=1;i<=n;i++) dis[i]=-1e18;
        queue<int> q;
        q.push(1);
        dis[1]=0;
        while(q.size()){
                auto tp=q.front();q.pop();
                //cerr<<tp<<'\n';
                for(int e=hd[tp];e;e=nxt[e]){
                       // cerr<<to[e]<<'\n';
                        if(dis[to[e]]<dis[tp]+w[e]){
                                dis[to[e]]=dis[tp]+w[e];
                                q.push(to[e]);
                        }
                }
        }
        int ret=0;
        for(int i=1;i<=n;i++) ret=max(ret,dis[i]);
        return ret;
}
signed main(){
        ios_base::sync_with_stdio(0),cin.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>h[i];
        int x,y;
        for(int i=1;i<=m;i++){
                cin>>x>>y;
                if(h[x]>h[y]){
                        addE(x,y,h[x]-h[y]);
                        addE(y,x,(h[y]-h[x])*2);
                }else{
                        addE(x,y,(h[x]-h[y])*2);
                        addE(y,x,h[y]-h[x]);
                }
        }
        cout<<SPFA()<<'\n';
}
