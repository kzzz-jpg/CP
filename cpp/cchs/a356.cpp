#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nd{
    int v,a,b;
    bool operator<(nd o) const{
        if(a==o.a) return b>o.b;
        return a<o.a;
    }
} a[200500];
int tr[800500];
int query(int l,int r,int L,int R,int id){
    if(l>R||r<L) return 0;
    if(L<=l&&r<=R) return tr[id];
    int mid=l+r>>1;
    //cerr<<l<<' '<<r<<' '<<L<<' '<<R<<' '<<mid<<'\n';
    return max(query(l,mid,L,R,id<<1),query(mid+1,r,L,R,id<<1|1));
}
void upd(int l,int r,int pos,int v,int id){
    if(pos>r||pos<l) return;
    if(l==r){
        tr[id]=max(tr[id],v);
        return;
    }
    int mid=l+r>>1;
    upd(mid+1,r,pos,v,id<<1|1);
    upd(l,mid,pos,v,id<<1);
    tr[id]=max(tr[id<<1],tr[id<<1|1]);
}
vector<int> lsh;
int n,dp[200500],ans;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].v);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].a);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].b),lsh.push_back(a[i].b);
    sort(a+1,a+1+n);
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
    for(int i=1;i<=n;i++) a[i].b=lower_bound(lsh.begin(),lsh.end(),a[i].b)-lsh.begin()+1;
    for(int i=1;i<=n;i++){

        dp[i]=query(1,n,a[i].b,n,1)+a[i].v;
        ans=max(ans,dp[i]);
        //cerr<<query(1,n,a[i].b,n,1)<<' '<<dp[i]<<'\n';
        upd(1,n,a[i].b,dp[i],1);
    }
    printf("%lld",ans);
}