#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long 
int a[1005000];
int n;
int ans=0;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+2,a+n+1,greater<int>());
    ans=a[1];
    for(int i=2;i<=n;i++){
        ans+=a[i]-a[i-1]+a[i];
    }
    cout<<ans<<'\n';
}