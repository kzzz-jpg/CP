#include<bits/stdc++.h>
using namespace std;
struct nd{
    int l,r;
    bool operator<(nd o)const{
        return l<o.l;
    }
} a[200500];
int n,m;
int dp[200500],ans;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i].l>>a[i].r;
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<i;j++){
            if(a[j].r<=a[i].l)
                dp[i]=max(dp[i],dp[j]);
        }
        dp[i]+=a[i].r-a[i].l;
    }
    cout<<ans<<'\n';
}