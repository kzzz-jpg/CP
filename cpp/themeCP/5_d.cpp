#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[2050][2050];
pair<int,int> pos[1000500];
int n;
void solve() {
  cin>>n;
  //cerr<<1<<'\n';
  //cerr<<pos[n].first<<' '<<pos[n].second<<'\n';
  cout<<dp[pos[n].first][pos[n].second]<<'\n';
}
signed main() {
  int cnt=2;
  dp[1][1]=1;
  pos[1]={1,1};
  for(int i=2;i<=2023;i++){
    for(int j=1;j<=i;j++){
     // if(i==1415) cerr<<i<<' '<<j<<'\n';
      dp[i][j]=dp[i-1][j]+dp[i-1][j-1]-dp[i-2][j-1]+cnt*cnt;
      if(cnt>=1000100) break;
      pos[cnt++]={i,j};
    }
   // cerr<<i<<'\n';
  }
//  cerr<<1<<'\n';
  int t = 0;
  cin >> t;
  while (t--)
    solve();
}
