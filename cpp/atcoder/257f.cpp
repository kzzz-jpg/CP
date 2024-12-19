#include<bits/stdc++.h>
#define int long long
using namespace std;
int hd[300500],to[600500],nxt[600500];
int n,m;
int cnt=1;
void addE(int a,int b){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        hd[a]=cnt++;
}
int dis[300500],rdis[300500];
void bfs1(){
        queue<int> q;
        q.push(1);
        while(q.size()){
                auto tp=q.front();q.pop();
                for(int e=hd[tp];e;e=nxt[e]){
                        if(to[e]==1||dis[to[e]]) continue;
                        dis[to[e]]=dis[tp]+1;
                        q.push(to[e]);
                }
        }
}
void bfs2(){
        queue<int> q;
        q.push(n);
        while(q.size()){
                auto tp=q.front();q.pop();
                for(int e=hd[tp];e;e=nxt[e]){
                        if(rdis[to[e]]||to[e]==n) continue;
                        rdis[to[e]]=rdis[tp]+1;
                        q.push(to[e]);
                }
        }
}
int ans;
signed main(){
        cin>>n>>m;
        int x,y;
        for(int i=1;i<=m;i++){
                cin>>x>>y;
                addE(x,y);
                addE(y,x);
        }
        bfs1();
        bfs2();
        //for(int i=0;i<=n;i++) cerr<<dis[i]<<' '<<rdis[i]<<'\n';
        for(int i=1;i<=n;i++){
                ans=99999999;
                if(dis[n])ans=min(ans,dis[n]);
                if((i==1||dis[i])&&(rdis[0])) ans=min(ans,dis[i]+rdis[0]);
                if(dis[0]&&(i==n||rdis[i])) ans=min(ans,dis[0]+rdis[i]);
                if(dis[0]&&rdis[0]) ans=min(ans,dis[0]+rdis[0]);
                if(ans==99999999) cout<<-1<<'\n';
                else cout<<ans<<'\n';
        }
}
