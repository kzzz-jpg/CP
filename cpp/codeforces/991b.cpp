#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
        int n;
        cin>>n;
        vector<int> v(n);
        int sum=0;
        for(auto &x:v) cin>>x,sum+=x;
        if(sum%n) return cout<<"NO\n",void();
        sum/=n;
        for(int i=1;i<n-1;i++) v[i+1]+=v[i-1]-sum,v[i-1]=sum;
        if(v[n-1]!=sum) cout<<"No\n";
        else cout<<"Yes\n";
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
