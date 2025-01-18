#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,ans=1;
    cin>>n;
    while(n>3){
        ans<<=1;
        n>>=2;
    }
    cout<<ans<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}