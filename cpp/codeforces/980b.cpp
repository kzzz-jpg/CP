#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[200500];
int nw,ans;
void solve(){
    cin>>n>>k,nw=0,ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++,ans++){
        if(k<=(a[i]-nw)*(n-i+1)){
            ans+=k;
            break;
        }
        k-=(a[i]-nw)*(n-i+1);
        ans+=(a[i]-nw)*(n-i+1);
        nw=a[i];
    }
    cout<<ans<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}