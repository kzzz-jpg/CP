#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100500];
int nw,ans;
signed main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        if(nw<0) nw=0;
        nw+=a[i];
        ans=max(ans,nw);
    }
    cout<<ans<<'\n';
}