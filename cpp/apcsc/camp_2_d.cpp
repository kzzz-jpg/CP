#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200500;
int n,A[N],fa[N],rt,ans;
int hd[N],to[N<<1],nxt[N<<1];
int nt[200500],pos[200500];
vector<int> lis;
int cnt=1;
void addE(int a,int b){
  nxt[cnt]=hd[a];
  to[cnt]=b;
  hd[a]=cnt++;
}
void dfs(int x,int par){
  int it=lower_bound(lis.begin(),lis.end(),A[x])-lis.begin();
  if(it==lis.size()) {
    lis.push_back(A[x]);
    pos[x]=it;
    nt[x]=-1e18;
  }else{
    nt[x]=lis[it];
    lis[it]=A[x];
    pos[x]=it;
  }
  if((int)lis.size()>ans) {
    //for(auto xx:lis) cerr<<xx<<' ';cerr<<'\n';
    ans=(int)lis.size();
  }
  for(int e=hd[x];e;e=nxt[e]){
    if(to[e]==par) continue;
    dfs(to[e],x);
  }
  if(nt[x]==-1e18){
    lis.pop_back();
  }else{
    lis[pos[x]]=nt[x];
  }
}
signed main(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>A[i],fa[i]=i;
  int x,y;
  for(int i=1;i<n;i++){
    cin>>x>>y;
    x++,y++;
    fa[y]=x;
    addE(x,y);
    addE(y,x);
  }
  rt=1;
  while(rt!=fa[rt]) rt=fa[rt];
  dfs(rt,0);
  cout<<ans<<'\n';
}
