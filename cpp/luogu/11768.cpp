#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll a,b,l,k;
    scanf("%lld%lld%lld%lld",&a,&b,&k,&l);
    ll ans=0;
    if(l){
        ll dt=min(k,a/l);
        k-=dt;a-=dt*l;
        dt=min(k,b/l);
        k-=dt;b-=dt*l;
        if(abs(a-l)>abs(b-l)) swap(a,b);
        if(k&&a>abs(a-l)) a-=l,k--;
        if(k&&b>abs(b-l)) b-=l,k--;
    }
    ans+=abs(a)+abs(b);
    printf("%lld\n",ans);
}
signed main(){
    int t=1;
    scanf("%d",&t);
    while(t--) solve();
}