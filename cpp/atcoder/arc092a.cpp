#include<bits/stdc++.h>
using namespace std;
int n;
struct pt{
        int x,y,cnt;
        bool operator <(pt o)const{
                return cnt<o.cnt;
        }
}a[200],b[200];
int dp[200][200];
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
        for(int i=1;i<=n;i++) cin>>b[i].x>>b[i].y;
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                        if(a[i].x<b[j].x&&a[i].y<b[j].y) a[i].cnt++,b[j].cnt++;
                }
        }
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        sort(b+1,b+1+n);
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                        if(a[i].x<b[j].x&&a[i].y<b[j].y) dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
                        cerr<<dp[i][j]<<' ';
                }
                cerr<<'\n';
        }
        cout<<dp[n][n]<<'\n';
}
