//b-a>a 
//b>2a 
//b-a<a 
//b<2a
//b-a_i>=a_{i-1}
//b>=
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200500],b[200500];
int n,m;
void solve(){
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int j=1;j<=m;j++) cin>>b[j];
  sort(b+1,b+1+m);
  a[1]=min(a[1],b[1]-a[1]);
  int it;
  for(int i=2;i<=n;i++){
    it=lower_bound(b+1,b+1+m,a[i]+a[i-1])-b;
    if((it>m||it<1)&&a[i]<a[i-1]){
      cout<<"No\n";
      return;
    }
    else if(it<=m&&a[i]<a[i-1]) a[i]=b[it]-a[i];
    else if(it>=1&&it<=m) a[i]=min(a[i],b[it]-a[i]);
  }
  cout<<"Yes\n";
}
signed main(){
  int t=1;
  cin>>t;
  while(t--) solve();
}
