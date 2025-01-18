#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    int x=0,y=0,a,b,s,t;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        x+=a,y+=b;
        if(i==1) s=x,t=y;
    }
    x+=m,y+=m;
    int ans=(x-s)*2+(y-t)*2;
    cout<<ans<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}