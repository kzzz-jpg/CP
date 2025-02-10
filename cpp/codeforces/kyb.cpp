#include "bits/stdc++.h"
using namespace std;
map<int,int> mp;
bool flag=0;
int n,a[200500];
void dfs(int i,int sum){
    if(i>n){
        //cerr<<sum<<'\n';
        if(sum==0) flag=1;
        return;
    }
    dfs(i+1,sum-a[i]);
    dfs(i+1,sum+a[i]);
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
    sort(a+1,a+1+n);
    n=unique(a+1,a+1+n)-a-1;
    for(int i=1;i<=n;i++) a[i]*=mp[a[i]];
    dfs(1,0);
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
}