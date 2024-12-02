#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int b[300500],d[300500],x[300500],p[300500],ans[300500];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>x[i];
    ans[1]=b[1];
    for(int i=2;i<=n;i++){
        ans[i]=min(b[i],ans[i-1]+d[i-1]);
    }
    for(int i=n-1;i;i--){
            ans[i]=min(b[i],ans[i+1]+d[i]);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}
