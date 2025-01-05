#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[400500];
int n,m,sum=0;
int ans;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    sort(a+1,a+1+n);
    for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];
    for(int i=1;i<=n;i++){
        int l=i,r=i;
        int ret=a[i];
        while(r+1-l+1<=n&&(a[r+1]-a[r]+m)%m<=1) ret+=a[++r];
        ans=max(ans,ret);
        i=r;
    }
    cout<<sum-ans<<'\n';
}