#include<bits/stdc++.h>
using namespace std;
int n,rt=1,ans;
int A[200500];
int fa[200500],cnt=1,deg[200500];
int nxt[400500],hd[200500],to[400500];
vector<int> v;
void addE(int a,int b){
  nxt[cnt]=hd[a];
  to[cnt]=b;
  hd[a]=cnt++;
}
int LIS(){
  vector<int> ret;
  for(auto x:v){
    auto it=lower_bound(ret.begin(),ret.end(),x);
    if(it==ret.end()) ret.push_back(x);
    else *it=x;
  }
  return (int)ret.size();
}
void dfs(int x,int par){
  cerr<<x<<' '<<par<<'\n';
  v.push_back(A[x]);
  if(deg[x]==1) ans=max(ans,LIS());
  for(int e=hd[x];e;e=nxt[e])if(to[e]!=par) dfs(to[e],x);
  v.pop_back();
}
signed main(){
  cin>>n;
  for(int i=1;i<=n;i++) cin>>A[i],fa[i]=i;
  int x,y;
  for(int i=1;i<n;i++){
    cin>>x>>y;
    x++,y++;
    deg[x]++;
    deg[y]++;
    addE(x,y);
    addE(y,x);
    fa[y]=x;
  }
  while(rt!=fa[rt]) rt=fa[rt];
  dfs(rt,0);
  cout<<ans<<'\n';
}
