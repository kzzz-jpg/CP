#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n,m;
        cin>>n>>m;
        vector<string> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int ans=0;
        for(int i=0;i<n;i++){
                if(m>=v[i].size()) m-=v[i].size(),ans++;
                else break;
        }
        cout<<ans<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
