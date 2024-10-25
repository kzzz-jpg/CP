#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
using namespace std;
#define ll long long
//#define int ll
#define lc (id<<1)
#define rc ((id<<1)|1)
/*vector<ll> mx(1200001,-9223372036854775806);
ll query(int l, int r, int L, int R, int id){
    if(l <= L && R <= r) return mx[id];
    int M = (L + R) / 2;
    if(r <= M)
        return query(l, r, L, M, lc);
    else if(l > M) 
        return query(l, r, M + 1, R, rc);
    else 
        return max(query(l, r, L, M, lc), query(l, r, M + 1, R, rc));
}
void modify(int x,int v,int L,int R,int id){
    if(L==R){
        mx[id]=v;
        return;
    }
    int mid=(L+R)/2;
    if(x<=mid) modify(x,v,L,mid,lc);
    else modify(x,v,mid+1,R,rc);
    mx[id]=max(mx[lc],mx[rc]);
    return;
}*/
signed main() {
    fast;
    int n,m;
    cin>>n>>m;
    int s;
    cin>>s;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    vector<bool> vis(n,false);
    vector<int> dis(n,0);
    pair<int,int> ans={0,0};
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        auto tp=q.front();
        q.pop();
        for(auto to:g[tp]){
            if(!vis[to]){
                dis[to]=dis[tp]+1;
                ans.first++;
                ans.second+=dis[to];
                vis[to]=true;
                q.push(to);
            }
        }
    }
    cout<<ans.first<<endl<<ans.second<<endl;
    return 0;
}