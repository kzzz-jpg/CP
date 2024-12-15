#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    int ans=1,nw=1;
    while(nw<n){
        nw=nw*2+2;
        ans++;
    }
    cout<<ans<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}