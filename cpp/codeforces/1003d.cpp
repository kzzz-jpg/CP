#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool comp(vector<int> &a,vector<int> &b){
  int ret1=0,ret2=0;
  for(int i=1;i<=m;i++){
    ret1+=a[i]*(2*m-i+1);
    ret1+=b[i]*(m-i+1);
    ret2+=a[i]*(m-i+1);
    ret2+=b[i]*(2*m-i+1);
  }
  return ret1>ret2;
}
void solve(){
  cin>>n>>m;
  vector<vector<int>> g(n+1,vector<int>(m+1));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>g[i][j];
    }
  }
  sort(g.begin()+1,g.end(),comp);
  int ans=0,cnt=1;
  for(int i=n;i>=1;i--){
    for(int j=m;j>=1;j--){
      ans+=g[i][j]*cnt;
      cnt++;
    }
  }
  cout<<ans<<'\n';
}
signed main(){
  int t=1;
  cin>>t;
  while(t--) solve();
}
