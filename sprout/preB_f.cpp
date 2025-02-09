#include<bits/stdc++.h>
using namespace std;
int n,a[1000500];
int dpl[1000500],dpr[1000500];
int ans[1000500];
signed main(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++){
    if(i-2>=1&&a[i-1]==1&&a[i]==0&&a[i-2]==0){
      dpl[i]=dpl[i-2]+1;
    }
  }
  for(int i=n;i>=1;i--){
    if(i+2<=n&&a[i]==0&&a[i+2]==0&&a[i+1]==1){
      dpr[i]=dpr[i+2]+1;
    }
  }
  for(int i=1;i<=n;i++){
    if(a[i]==0){
      ans[i]=-1;
      continue;
    }
    if(i-2>=1&&a[i-1]==1&&a[i-2]==0){
      ans[i]=max(ans[i],dpl[i-2]+1);
    }
    if(i+2<=n&&a[i+1]==1&&a[i+2]==0){
      ans[i]=max(ans[i],dpr[i+2]+1);
    }
    if(i-1>=1&&a[i-1]==0) ans[i]=max(ans[i],1);
    if(i+1<=n&&a[i+1]==0) ans[i]=max(ans[i],1);
  }
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" \n"[i==n];
  }
}
