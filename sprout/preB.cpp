#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000500];
int lf[1000500],r[1000500];
int n;
signed main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  int nw;
  for(int i=3;i<=n;i++){
    nw=i;
    while(nw-2>=1&&a[nw-1]==1&&a[nw-2]==0){
      lf[i]++;
      nw-=2;
    }
  }
  for(int i=n-2;i>=1;i--){
    nw=i;
    while(nw+2<=n&&a[nw+1]==1&&a[nw+2]==0){
      r[i]++;
      nw+=2;
    }
  }
  for(int i=1;i<=n;i++){
    if(a[i]==0){
      cout<<-1<<" \n"[i==n];
    }else{
      if(lf[i]>=1||r[i]>=1){
        cout<<max(lf[i],r[i])<<" \n"[i==n];
      }else if((i-1>=1&&a[i-1]==0)||(i+1<=n&&a[i+1]==0)){
        cout<<1<<" \n"[i==n];
      }else{
        cout<<0<<" \n"[i==n];
      }
    }
  }
}
