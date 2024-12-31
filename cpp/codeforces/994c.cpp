#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    x--,y--;
    vector<int> ans(n);
    int fg=0;
    ans[x]=2;
    for(int i=x+1;i!=x;i=(i+1)%n,fg^=1) ans[i]=fg;
    if(ans[y]==0&&ans[(x+1)%n]==0&&ans[(x-1+n)%n]==0) ans[x]=1;
    for(auto ggg:ans) cout<<ggg<<' ';
    cout<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}