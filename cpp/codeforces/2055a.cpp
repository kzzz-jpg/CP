#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    if(l>r) swap(l,r);
    if((r-l)&1) cout<<"No\n";
    else cout<<"Yes\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}