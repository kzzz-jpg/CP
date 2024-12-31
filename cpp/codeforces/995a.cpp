#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        cin>>b[0];
        for(int i=0;i<n-1;i++) cin>>b[i];
        b[n-1]=0;
        for(int i=0;i<n;i++) a[i]-=b[i];
        sort(a.begin(),a.end(),greater<int>());
        int ans=0;
        for(auto x:a) {
                if(x<=0) break;
                else ans+=x;
        }
        cout<<ans<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
