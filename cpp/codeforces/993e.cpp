#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
        int k,l1,l2,r1,r2;
        cin>>k>>l1>>r1>>l2>>r2;
        int nw=1;
        int ans=0;
        while(nw<=r1*r2){
                cerr<<nw<<' '<<r1*r2<<'\n';
                for(int i=max(1LL,l1);i<=min(r1,(int)(sqrt(nw)+1));i++){
                        if(nw%i==0&&nw/i>=l2&&nw/i<=r2) ans++;
                }
                nw*=k;
        }
        cout<<ans<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
