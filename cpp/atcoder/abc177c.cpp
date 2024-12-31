#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e9+7;
int a[200500];
int pre[200500];
int n,ans=0;
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=n;i>=1;i--) pre[i]=(pre[i+1]+a[i])%P;
        for(int i=1;i<=n;i++){
                ans+=a[i]*pre[i+1];
                ans%=P;
        }
        cout<<ans<<'\n';
}
