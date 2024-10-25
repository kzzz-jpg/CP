#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[200001],nxt[1000001],to[1000001],w[1000001];
int dpt[200001],low[200001],pt[200001];
stack<int> s;
int cnt=1;
int cnt2=1;
int tme=0;
int n,m,aa,bb,cc;
void addE(int a,int b,int c){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    w[cnt]=c;
    hd[a]=cnt++;
}
int Hd[200001],Nxt[1000001],To[1000001],W[1000001];
void addE2(int a,int b,int c){
    Nxt[cnt]=Hd[a];
    To[cnt]=b;
    W[cnt]=c;
    Hd[a]=cnt++;
}
void tarjan(int x,int par){
    s.push(x);
    dpt[x]=low[x]=++tme;
    for(int e=hd[x];e;e=nxt[e]){
        int v=to[e];
        if(v==par) continue;
        if(dpt[v]){
            low[x]=min(low[x],low[v]);
        }else{
            tarjan(v,x);
            low[x]=min(low[x],low[v]);
        }
    }
    if(low[x]==dpt[x]){
        while(s.top()!=x){
            pt[s.top()]=cnt2;
            s.pop();
        }
        pt[x]=cnt2++;
        s.pop();
    }
}
int dis[200001];
bool vs[200001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
void dijkstra(){
    pq.push({0,pt[1]});
    while(!pq.empty()){
        auto tp=pq.top();pq.pop();
        if(vs[tp.second]) continue;
        vs[tp.second]=1;
        dis[tp.second]=tp.first;
        for(int e=Hd[tp.second];e;e=Nxt[e]){
            if(!vs[To[e]]){
                pq.push({tp.first+W[e],To[e]});
            }
        }
    }
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>aa>>bb>>cc;
        addE(aa,bb,cc);
    }
    tarjan(1,0);
    cnt=1;
    for(int i=1;i<=n;i++){
        for(int e=hd[i];e;e=nxt[e]){
            if(pt[to[e]]!=pt[i]){
                addE2(pt[i],pt[to[e]],w[e]);
            }
        }
    }
    dijkstra();
    cout<<dis[pt[n]]<<'\n';
}