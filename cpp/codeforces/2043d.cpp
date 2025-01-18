#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int l,r,g,ans=-1,ansl=-1,ansr=-1,rl,rr;
    cin>>l>>r>>g;
    rl=l,rr=r;
    l/=g,r/=g;
    for(int i=0;i<=35;i++){
        for(int j=0;j<=35;j++){
            if(l+i<=0||r-j<=0) continue;
            if((l+i)*g<rl||(r-j)*g>rr) continue;
            if(l+i>r-j||__gcd(l+i,r-j)>1) continue;
            if(r-j-l-i>ans) ansl=(l+i)*g,ansr=(r-j)*g,ans=r-j-l-i;
        }
    }
    cout<<ansl<<' '<<ansr<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}