#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans=0;
int a[500500];
bool vs[500500];
multiset<int> s;
int chk(int l,int r){
    int mn=1e18,mx=0;
    for(int i=l;i<=r;i++){
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    return mx-mn;
}
void test(){
    int ret=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(chk(i,j)<=k){
                ret++;
                cerr<<i<<' '<<j<<'\n';
            }
        }
    }
    cerr<<ret<<'\n';
}
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    test();
    //s.insert(a[1]);
    //for(int l=1,r=1;l<=n;l++){
    //    while((r+1<=n)&&abs(a[r+1]-*s.begin())<=k&&abs(a[r+1]-*prev(s.end()))<=k) s.insert(a[++r]);
    //    if(vs[r]==0) {
    //        ans+=(r-l+1)*(r-l+2)/2;
    //        vs[r]=1;
    //        cerr<<l<<' '<<r<<'\n';
    //    }
    //    s.erase(s.find(a[l]));
    //}
    //printf("%lld",ans);
}