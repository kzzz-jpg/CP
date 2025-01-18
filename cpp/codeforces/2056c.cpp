#include<bits/stdc++.h>
using namespace std;
int n;
void solve(){
    cin>>n;
    cout<<1<<' ';
    for(int i=1;i<=n-2;i++) cout<<i<<' ';
    cout<<1<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}