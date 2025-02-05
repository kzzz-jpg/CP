#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int n;
int a[200500],fa[200500],pos[200500];
int hd[200500],nxt[400500],to[400500],cnt,rt,ans;
vector<stack<int>> LIS;

void addE(int a,int b){
  hd[a]=++cnt; nxt[cnt]=hd[a]; to[cnt]=b;
}
int qry(int x){
  int l=0,r=LIS.size()-1,mid;
  while(l<r){
    mid=(l+r+1)>>1;
    if(LIS[mid].top()<=x) l=mid;
    else r=mid-1;
  }
  return l;
}
void dfs(int x,int par){
  cerr<<x<<' '<<par<<'\n';
  stack<int> tmp;
  tmp.emplace(a[x]);
  int it=qry(a[x]);
  if(it==LIS.size()) LIS.push_back(stack<int>()),LIS[it].push(a[x]);
  else LIS[it].push(a[x]);
  pos[x]=it;
  ans=max(ans,(int)LIS.size());
  for(int e=hd[x];e;e=nxt[e]){
    if(to[e]==par) continue;
    dfs(to[e],x);
  }
  LIS[pos[x]].pop();
  if(LIS[pos[x]].empty()) LIS.pop_back();
}
signed main(){
  cin>>n;
  for(int i=1;i<=n;i++) fa[i]=i;
  int x,y;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<n;i++){
    cin>>x>>y;
    x++,y++;
    addE(x,y);addE(y, x);
    fa[y]=x;
  }
  rt=1;
  while(fa[rt]!=rt) rt=fa[rt];
  dfs(rt,0);
  cout<<ans<<'\n';
}
