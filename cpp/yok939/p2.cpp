#include<bits/stdc++.h>
using namespace std;
#define int long long
int g[20][20];
int n,m;
int a,b;
int ans=1e15;
vector<vector<int>> v(3);
void f(int i){
    if(i>n){
        ans=min(ans,(int)(max({v[0].size(),v[1].size(),v[2].size()})-min({v[0].size(),v[1].size(),v[2].size()})));
        return;
    }
    bool b=1;
    for(auto x:v[0]){
        if(g[x][i]){
            b=0;
            break;
        }
    }
    if(b){
        v[0].push_back(i);
        f(i+1);
        v[0].pop_back();
    }
    b=1;
    for(auto x:v[1]){
        if(g[x][i]){
            b=0;
            break;
        }
    }
    if(b){
        v[1].push_back(i);
        f(i+1);
        v[1].pop_back();
    }
    b=1;
    for(auto x:v[2]){
        if(g[x][i]){
            b=0;
            break;
        }
    }
    if(b){
        v[2].push_back(i);
        f(i+1);
        v[2].pop_back();
    }
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
    }
    f(1);
    if(ans==1e15) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}