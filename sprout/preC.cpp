#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000500];
int x,y,ans;
signed main(){
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  cin>>x>>y;
  for(int i=1,r=1;i<=n;i=r+1,r=i){
    while(r+1<=n&&(a[r+1]-a[r]+1)*x+y<=2*(x+y)){
      r++;
    }
    ans+=(a[r]-a[i]+1)*x+y;
  }
  cout<<ans<<'\n';
}
