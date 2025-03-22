#include<bits/stdc++.h>
#define DEBUG
#define int long long
using namespace std;
int n,k,a[200500],b[200500],c[200500];
int tmp[200500];
int chk(int d){
  int l=1;
  for(int i=1;i<=n;i++){
    tmp[i]=a[i]+b[i]*d;
  }
  sort(tmp+1,tmp+1+n);
  for(int i=1;i<=n;i++){
    if(tmp[i]>c[l]) l++;
  }
  return l-1;
}
void solve(){
  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
  for(int i=1;i<=n;i++) cin>>c[i];
  sort(c+1,c+1+n);
  int l=0,r=1e9+7;
  while(l<r){
    int mid=l+r>>1;
    if(chk(mid)<k) l=mid+1;
    else r=mid;
  }
  if(r==1e9+7) cout<<-1<<'\n';
  else cout<<l<<'\n';
}
signed main(){
  #ifdef DEBUG 
  freopen("in.in","r",stdin);
  freopen("tmp","w",stdout);
  #endif
  int t=1;
  cin>>t;
  while(t--) solve();
}
