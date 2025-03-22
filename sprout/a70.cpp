#include<bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 rg(rd());
int n;
double a[100],b[100],c[100];
double ans=0,anst=0,x=0;
double getn(double t){
  double ret=0;
  for(int i=1;i<=n;i++) ret=max(ret,a[i]*(x-b[i])*(x-b[i])+c[i]);
  return ret;
}
void sa(){
  double T=300,low=0.98,ed=1e-7;
  for(;T>ed;T*=low){
    double dx=((rg()%1000000+rg()%1000000)-1000000)*0.000001*T;
    x+=dx;
    if(x>300) {x-=dx;continue;}
    double nw=getn(x);
    if(nw<ans){
      ans=nw,anst=x;
    }else if(exp((ans-nw)/T)<(double(rg())/(rg.max()-1))) x-=dx;
  }
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
  anst=0;
  x=0;
  ans=0;
  ans=getn(anst);
  for(int i=1;i<50;i++) sa();
  cout<<anst<<'\n';
}
signed main(){
  int t=1;
  cin>>t;
  while(t--) solve();
}
