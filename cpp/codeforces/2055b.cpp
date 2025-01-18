#include<bits/stdc++.h>
using namespace std;
int n;
int a[200500],b[200500];
void solve(){
    cin>>n;
    int mn=0x3f3f3f3f,dif=0,mx=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        if(a[i]<b[i]) dif++,mx=max(mx,b[i]-a[i]);
        else mn=min(mn,a[i]-b[i]);
    }
    if(dif>1||mx>mn) cout<<"no\n";
    else cout<<"yes\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}