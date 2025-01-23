#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,h,ans,nw;
int tmp[200500],a[200500][2];
void solve(){
    cin>>n>>m>>h;
    ans=1;
    for(int i=1;i<=n;i++){
        a[i][0]=a[i][1]=0;
        nw=0;
        for(int j=1;j<=m;j++) cin>>tmp[j];
        sort(tmp+1,tmp+1+m);
        for(int j=1;j<=m;j++){
            if(nw+tmp[j]>h) break;
            a[i][0]++;
            nw+=tmp[j];
            a[i][1]+=nw;
        }
        if(i>1&&(a[i][0]>a[1][0]||(a[i][0]==a[1][0]&&a[i][1]<a[1][1]))) ans++;
    }
    cout<<ans<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}