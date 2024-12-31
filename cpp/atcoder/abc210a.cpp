#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,x,y,ans;
signed main(){
    cin>>n>>a>>x>>y;
    for(int i=1;i<=n;i++){
        if(i>a) ans+=y;
        else ans+=x;
    }
    cout<<ans<<'\n';
}