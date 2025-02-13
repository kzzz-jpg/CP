#include<bits/stdc++.h>
using namespace std;
string s;
void solve(){
  cin>>s;
  s.pop_back(),s.pop_back();
  cout<<s<<'i'<<'\n';
}
signed main(){
  int t=1;
  cin>>t;
  while(t--) solve();
}
