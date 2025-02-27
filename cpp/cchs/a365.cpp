#include<bits/stdc++.h>
#define int long long
int n,m,k;
int f(int x){
    int ret=0;
    if(x-k+1<1) ret+=(1+x)*x/2+(k-x);
    else ret+=(2*x-k+1)*k/2;
    if(x-n+k<1) ret+=x*(x-1)/2+n-k-x+1;
    else ret+=(n-k)*(2*x+k-n-1)/2;
    return ret;
}
void solve(){
    scanf("%lld%lld%lld",&n,&m,&k);
    int l=0,r=1e9;
    while(l<r){
        int mid=l+r>>1;
        if(f(mid)>m) r=mid;
        else l=mid+1;
    }
   // printf("%lld %lld %lld\n",n,m,k);
    printf("%lld\n",l-1);
}
signed main(){
    int t=1;
    scanf("%lld",&t);
    while(t--) solve();
}