#include<bits/stdc++.h>
#define int long long
int n,m,s,p,q,r,l,a[200500],ans;
signed main(){
    scanf("%lld%lld%lld",&n,&m,&s);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld%lld",&p,&q,&r,&l);
        for(int j=p;j<=q;j+=r+1) a[j]+=l;
    }
    for(int i=1;i<=n;i++){
        if(a[i]>s)ans++;
    }
    printf("%lld",ans);
}