#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[3005][3005];
int n,m;
string ans;
signed main(){
        cerr<<1<<'\n';
        cin>>a>>b;
        n=a.size(),m=b.size();
        a=" "+a;
        b=" "+b;
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++) dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+(a[i]==b[j])});
        }
        int x=n,y=m;
        while(x>=1&&y>=1){
                if(a[x]==b[y]){
                        ans.push_back(a[x]);
                        x--,y--;
                }else if(dp[x-1][y]>dp[x][y-1]) x--;
                else y--;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';
}
