#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200500];
void solve(){
  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>a[i];
  k=n-k+1;
  a[++n]=0;
  for(int nw=1,pos=1,op=0;nw<=n;pos++,op^=1){
    for(int i=0;i<k;i++){
      if(a[pos+i]!=nw+i){
        cout<<nw+i<<'\n';
        return ;
      }
    }
  }
}
signed main(){
  int t=1;
  cin>>t;
  while(t--) solve();
}
