#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[200500];
const int P=10;
int fp(int x,int y){
  int ret=1;
  while(y){
    if(y&1) ret=(ret*x)%P;
    x=(x*x)%P;
    y>>=1;
  }
  return ret;
}
signed main(){
  cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
  int l,r,k,ans;
  while(q--){
    cin>>l>>r>>k;
    ans=0;
    for(int i=l;i<=r;i++){
      ans=(ans+fp(a[i],k))%P;
    }
    cout<<ans<<'\n';
  }
}
