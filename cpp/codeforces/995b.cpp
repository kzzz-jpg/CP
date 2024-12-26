#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int ans=n/(a+b+c)*3;
        if(n%(a+b+c)>a+b) ans+=3;
        else if(n%(a+b+c)>a) ans+=2;
        else if(n%(a+b+c))ans++;
        cout<<ans<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
