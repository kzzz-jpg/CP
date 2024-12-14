#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
int a[100500];
int check(int x){
        int ret= x-(upper_bound(a+1,a+1+n,x)-a-1);
        return ret;
}
signed main(){
        cin>>n>>q;
        for(int i=1;i<=n;i++){
                cin>>a[i];
        }
        int k;
        while(q--){
                cin>>k;
                int ans=2e18;
                for(int j=1e18;j;j>>=1){
                        while(ans-j>0&&check(ans-j)>=k) ans-=j;
                }
                cout<<ans<<'\n';
        }
}
