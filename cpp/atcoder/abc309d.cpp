#include<bits/stdc++.h>
using namespace std;
int hd[300500],nxt[600500],to[600550];
int cnt=1;
void addE(int a,int b){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        hd[a]=cnt++;
}
int n1,n2,m;
int dis[300500];
int bfs(int st){
        queue<int> q;
        q.push(st);
        dis[st]=1;
        int ret=0;
        while(q.size()){
                auto tp=q.front();q.pop();
                ret=max(ret,dis[tp]);
                for(int e=hd[tp];e;e=nxt[e]){
                        if(dis[to[e]]) continue;
                        dis[to[e]]=dis[tp]+1;
                        q.push(to[e]);
                }
        }
        return ret;
}
signed main(){
        cin>>n1>>n2>>m;
        int x,y;
        for(int i=1;i<=m;i++){
                cin>>x>>y;
                addE(x,y);
                addE(y,x);
        }
        cout<<(bfs(1)+bfs(n1+n2)-1)<<'\n';
}
