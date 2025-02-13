#include<bits/stdc++.h>
using namespace std;
const int N=500500;
int n;
int a[N];
int ans[N],deg[N];
int cnt=1,hd[N],nxt[1000500],to[1000500];
int mp[500500];
void addE(int a,int b){
  nxt[cnt]=hd[a];
  to[cnt]=b;
  hd[a]=cnt++;
}
void dfs(int x,int par){
  for(int e=hd[x];e;e=nxt[e]) {
    if(++mp[a[to[e]]]>=2) ans[a[to[e]]]=1;
  }
  for(int e=hd[x];e;e=nxt[e]) mp[a[to[e]]]--;
  for(int e=hd[x];e;e=nxt[e]){
    if(to[e]==par) continue;
    if(a[x]==a[to[e]]) ans[a[x]]=1;
    if(a[par]==a[to[e]]) ans[a[par]]=1;
    dfs(to[e],x);
  }
}
void solve(){
  for(int i=1;i<=n;i++) deg[i]=a[i]=ans[i]=hd[i]=0;
  cnt=1;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  int x,y;
  for(int i=1;i<n;i++){
    cin>>x>>y;
    addE(x,y);
    addE(y,x);
    deg[x]++,deg[y]++;
  }
  dfs(1,0);
  for(int i=1;i<=n;i++)cout<<ans[i];
  cout<<'\n';
}
signed main(){
  int t=1;
  cin>>t;
  while(t--) solve();
}
