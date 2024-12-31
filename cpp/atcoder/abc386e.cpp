#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
int n,k,ans;
int a[200500];
void dfs(int nw,int i,int ch){
    if(i>n){
        ans=max(ans,nw);
        return;
    }
    if(ch<k) dfs(nw^a[i],i+1,ch+1);
    if(n-i+1>k-ch) dfs(nw,i+1,ch);
}
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(0,1,0);
    cout<<ans<<'\n';
}