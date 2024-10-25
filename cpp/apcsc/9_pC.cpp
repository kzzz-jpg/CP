#include<bits/stdc++.h>
#include<random>
using namespace std;
#define int long long
random_device rd;
mt19937 rg(rd());
int hd[200500],nxt[400500],to[400500];
int cnt=1;
int n,m;
int u,v,id;
char c;
struct mst{
    int a[9];
    bool operator > (mst ano) const{
        for(int i=0;i<9;i++){
            if(a[i]==ano.a[i]) continue;
            return a[i]>ano.a[i];
        }
    }
    void rev(){
        for(int i=0;i<4;i++){
            swap(a[i],a[8-i]);
        }
    }
};
map<int,mst> mp;
void addE(int a,int b){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    hd[a]=cnt++;
}
pair<int,mst> dfs(int x,int par,int d){
    mst ret=mp[x];
    int retn=x;
    if(d&1) ret.rev();
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]!=par){
            auto tp=dfs(to[e],x,d+1);
            mst comp=tp.second;
            int nw=tp.first;
            if(d&1) comp.rev();
            if(comp>ret) {
                ret=comp;
                retn=nw;
            }
        }
    }
    if(d&1) ret.rev();
    return {retn,ret};
}
void solve(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n+m-1;i++){
        cin>>u>>v;
        addE(u,v);
        addE(v,u);
    }
    for(int i=0;i<m;i++){
        cin>>id;
        for(int j=0;j<9;j++){
            cin>>mp[id].a[j];
        }
    }
    auto ans=dfs(1,1,1);
    cout<<ans.first<<'\n';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<ans.second.a[i*3+j]<<" \n"[j==2];
        }
    }
}
signed main(){
    int t=1;
    while(t--) solve();
}