#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,r,s,p;
string t;
bool dp[100500][3];// r for 0 ,s for 1,p for 2
int ans=0;
signed main(){
        cin>>n>>k;
        cin>>r>>s>>p;
        cin>>t;
        for(int i=0;i<k;i++){
                if(t[i]=='s') ans+=r,dp[i][0]=1;
                if(t[i]=='p') ans+=s,dp[i][1]=1;
                if(t[i]=='r') ans+=p,dp[i][2]=1;
        }
        for(int i=k;i<n;i++){
                if(t[i]=='s'&&!dp[i-k][0]) ans+=r,dp[i][0]=1;
                if(t[i]=='p'&&!dp[i-k][1]) ans+=s,dp[i][1]=1;
                if(t[i]=='r'&&!dp[i-k][2]) ans+=p,dp[i][2]=1;
        }
        cout<<ans<<'\n';
}
