#include<bits/stdc++.h>
using namespace std;
string s;
void solve(){
  cin>>s;
  for(int i=0;i+1<s.size();i++){
    if(s[i]==s[i+1]){
      cout<<1<<'\n';
      return;
    }
  }
  cout<<s.size()<<'\n';
}
signed main(){
  int t=1;
  cin>>t;
  while(t--) solve();
}
