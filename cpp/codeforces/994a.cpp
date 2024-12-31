#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    bool flag=1;
    for(auto x:a) if(x) flag=0;
    if(flag) return cout<<0<<'\n',void();
    flag=1;
    int i=0;
    for(;i<n;i++) if(a[i]) break;
    while(a.back()==0) a.pop_back();
    for(;i<a.size();i++) if(a[i]==0) flag=0;
    if(flag) return cout<<1<<'\n',void();
    else cout<<2<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}