#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
        int n,x,y,ans=0,sum=0;
        cin>>n>>x>>y;
        vector<int> a(n);
        for(auto &x:a) cin>>x,sum+=x;
        y=sum-y;
        x=sum-x;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
                ans+=max((int)(upper_bound(a.begin()+i+1,a.end(),x-a[i])-lower_bound(a.begin()+i+1,a.end(),y-a[i])),0LL);
        }
        cout<<ans<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
