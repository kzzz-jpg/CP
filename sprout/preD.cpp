#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
unsigned long long sum=0,ans=8e18;
int r[1010],c[1010];
bool chk(int x,int y){
  bool a=1,b=1,C=1,d=1;
  for(int i=1;i<=n;i++){
    if(r[i]%x!=0) a=0;
    if(r[i]%y!=0) C=0;
  }
  for(int j=1;j<=m;j++){
    if(c[j]%x!=0) b=0;
    if(c[j]%y!=0) d=0;
  }
  return (a&&d)||(b&&C);
}
signed main(){
  cin>>n>>m;
  int x;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>x;
      sum+=x;
      r[i]+=x;
      c[j]+=x;
    }
  }
  for(int i=1;i<=sqrt(sum)+5;i++){
    if(sum%i==0&&chk(i,sum/i)){
      ans=min(ans,(sum/i+i)*2);
    }
  }
  cout<<ans<<'\n';
}
