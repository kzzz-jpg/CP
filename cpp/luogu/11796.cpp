#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a[1000500],b[1000500],mn[1000500],suf[1000500],ans;
struct nd{
    int mn,suf;
    bool operator<(nd o) const{
        return suf>o.suf;
    }
} v[1000500];
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    mn[n]=a[n];suf[n]=b[n];
    v[n].suf=suf[n];v[n].mn=mn[n];
    for(int i=n-1;i>=1;i--){
        mn[i]=min(mn[i+1],a[i]);
        suf[i]=b[i]+suf[i+1];
        v[i].suf=suf[i];v[i].mn=mn[i];
    }
    sort(v+1,v+1+n);
    ll nw=0;
    for(int i=1;i<=n;i++){
        if(v[i].suf>0&&v[i].mn>nw) ans+=v[i].suf*(v[i].mn-nw),nw+=v[i].mn-nw;
    }
    printf("%lld\n",ans);
}