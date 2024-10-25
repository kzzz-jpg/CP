#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[200050],nxt[200050],to[200050],w[200040];
bool vs[200050];
int ans[200050];
int cnt=0,n,m;
void addE(int a,int b,int c){
    nxt[++cnt]=hd[a];
    to[cnt]=b;
    w[cnt]=c;
    hd[a]=cnt;
}
int aa,bb,cc;
void bfs(){
    queue<int> q;
    q.push(1);
    vs[1]=1;
    while(q.size()){
        auto tp=q.front();q.pop();
        for(int e=hd[tp];e;e=nxt[e]){
            if(!vs[to[e]]){
                ans[to[e]]=ans[tp]+w[e];
                vs[to[e]]=1;
                q.push(to[e]);
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
    for(int i=1;i<=n;i++) if(!vs[i]) bfs();
    for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';
}