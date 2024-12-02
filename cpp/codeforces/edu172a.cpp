#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n;i++){
        if(k<a[i]) break;
        k-=a[i];
    }
    cout<<k<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}