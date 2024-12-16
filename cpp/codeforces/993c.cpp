#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int fr=n,sc=n;
        int ans=0;
        fr=max(fr-a,0);
        ans+=min(n,a);
        sc=max(sc-b,0);
        ans+=min(n,b);
        ans+=min(c,fr+sc);
        cout<<ans<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
