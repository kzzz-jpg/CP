#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int tmp=n+1,tmp2=n+1;
    int ans=0,dep=1;
    for(;n>=k;){
        if(n&1) {
            if(dep==1) ans+=(n+1)>>1;
            else{
                int a_f=(n+1LL)>>1LL,num=1<<(dep-2),d=tmp2+tmp;
                cerr<<a_f<<' '<<num<<' '<<d<<'\n';
                ans+=((a_f*2+(num-1)*d)*num)>>1;
                a_f+=tmp;
                cerr<<a_f<<' '<<num<<' '<<d<<'\n';
                ans+=((a_f*2+(num-1)*d)*num)>>1;
            }
        }else tmp2++;
        n>>=1;
        dep++;
        tmp>>=1;
        tmp2>>=1;
    }
   // cerr<<'\n';
    cout<<ans<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}