#include<bits/stdc++.h>
using namespace std;
void solve(){
        int a,b;
        cin>>a>>b;
        cout<<a*b/__gcd(a,b)<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
