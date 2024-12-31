#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
        int n,k,ans=0;
        cin>>n>>k;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++){
                int ita=lower_bound(a.begin(),a.end(),a[i])-a.begin();
                int itb=lower_bound(b.begin(),b.end(),a[i])-b.begin();
                if(ita-itb<=k) ans=max(ans,a[i]*(n-itb));
        }
        for(int i=0;i<n;i++){
                int ita=lower_bound(a.begin(),a.end(),b[i])-a.begin();
                int itb=lower_bound(b.begin(),b.end(),b[i])-b.begin();
                if(ita-itb<=k) ans=max(ans,b[i]*(n-itb));
        }
        cout<<ans<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
