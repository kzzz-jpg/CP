#include "bits/stdc++.h"
#include <algorithm>
using namespace std;
#define int long long
int n,k,w[200500];
int chk(int x){
    int ret=0;
    for(int i=1;i<=n;i++){
        ret+=(upper_bound(w+i,w+1+n,x-w[i])-w-i);
    }
    return ret;
}
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>w[i];
    sort(w+1,w+1+n);
    int l=-1e18,r=1e18;
    k=(n+1)*n/2-k+1;
    while(l<r){
        int mid=l+r>>1;
        //cerr<<mid<<' '<<chk(mid)<<'\n';
        if(chk(mid)>=k){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    if(l&1){
        cout<<l<<'\n'<<2<<'\n';
    }else cout<<l/2<<'\n'<<1<<'\n';
}