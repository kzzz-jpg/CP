#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500500],n,q,fw[500500];
void add(int x,int v){
    for(;x<=n;x+=x&-x) fw[x]+=v;
}
int query(int x){
    int ret=0;
    for(;x;x-=x&-x) ret+=fw[x];
    return ret;
}
signed main(){
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int l,r,op,k;
    while(q--){
        scanf("%lld",&op);
        if(op==1){
            scanf("%lld%lld%lld",&l,&r,&k);
            add(l,k);
            add(r+1,-k);
        }else{
            scanf("%lld",&k);
            printf("%lld\n",query(k)+a[k]);
        }
    }
}