#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005],b[1050];
vector<pair<int,int>> Ans;
vector<set<int>> pos(1050);
signed main(){
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i],pos[a[i]].insert(i);
  sort(b+1,b+1+n);
  for(int i=1;i<=n;i++){
    cerr<<i<<'\n';
    if(a[i]==b[i]){
      pos[a[i]].erase(pos[a[i]].find(i));
      continue;
    }
    auto it=pos[b[i]].begin();
    Ans.push_back({i,*it});
    pos[a[i]].erase(i);
    pos[a[i]].insert(*it);
    swap(a[i],a[*it]);
    pos[b[i]].erase(it);
  }
  cout<<Ans.size()<<'\n';
  for(auto [x,y]:Ans){
    cout<<x<<' '<<y<<'\n';
  }
}
