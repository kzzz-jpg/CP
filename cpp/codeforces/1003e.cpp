#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[400500];
int cnt;
void solve(){
  for(int i=1;i<=n+m;i++) a[i]=0;
  cnt=0;
  cin>>n>>m>>k;
  int mx=max(n,m),mn=min(n,m);
  if(mx<k||abs(n-m)>k){
    cout<<-1<<'\n';
    return;
  }
  for(int i=1;i<=k;i++) a[++cnt]=1;
  mx-=k;
  while(mx&&mn){
    a[++cnt]=0;
    a[++cnt]=1;
    mx--;
    mn--;
  }
  if((mn==0&&mx+1>k)||(mx==0&&mn>k)){
    cout<<-1<<'\n';
    return;
  }
  if(mn==0) while(mx) a[++cnt]=1,mx--;
  for(int i=1;i<=n+m;i++){
    if(n<m) cout<<a[i];
    else cout<<(a[i]^1);
  }
  cout<<'\n';
}
signed main(){
  int t=1;
  cin>>t;
  while(t--) solve();
}
