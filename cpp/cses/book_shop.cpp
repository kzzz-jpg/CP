#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1000000007;
vector<vector<int>> g(200500);
vector<int> sz(200500,0);
void dfs(int x,int par){
    for(auto u:g[x]){
        if(u!=par){
            dfs(u,x);
            sz[x]+=sz[u]+1;
        }
    }
}
signed main() {
    int n,t1,t2;
    cin>>n>>t1>>t2;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(t2,-1);
    vector<int> ans;
    for(auto x:g[t2]){
        ans.push_back(sz[x]+1);
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<" ";
    return 0;
}