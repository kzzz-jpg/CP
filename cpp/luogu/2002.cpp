#include<bits/stdc++.h>
using namespace std;
struct nd{
    int v,in;
    bool operator < (nd o) const{
        return in<o.in;
    }
} g[100005];
int hd[100001],nxt[500001],to[500001];
int ans=0;
bool vs[100001];
int n,m;
int cnt=1;
void addE(int a,int b){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    hd[a]=cnt++;
}
void dfs(int x){
    vs[x]=1;
    for(int e=hd[x];e;e=nxt[e]){
        if(!vs[to[e]])
            dfs(to[e]);
    }
}
int main(){
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++) {
        cin>>a>>b;
        if(a==b) continue;
        addE(a,b);
        g[b].in++;
    }
    for(int i=1;i<=n;i++) g[i].v=i;
    sort(g+1,g+n+1);
    for(int i=1;i<=n;i++){
        if(!vs[g[i].v]){
            ans++;
            dfs(g[i].v);
        }
    }
    cout<<ans<<'\n';
}