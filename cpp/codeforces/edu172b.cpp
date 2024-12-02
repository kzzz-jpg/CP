#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    int t;
    for(int i=1;i<=n;i++){
        cin>>t;
        a[t]++;
    }
    int tw=0,sig=0;
    for(int i=1;i<=n;i++){
        if(a[i]>1) tw++;
        if(a[i]==1) sig++;
    }
    int ans=tw+((sig/2)+(sig&1))*2;
    cout<<ans<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}