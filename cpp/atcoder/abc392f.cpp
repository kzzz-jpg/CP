#include<bits/stdc++.h>
using namespace std;
int n,p[500500];
int tr[2000500],ans[500500];
void build(int l,int r,int id){
  if(l==r){
    tr[id]=1;
    return;
  }
  int mid=l+r>>1;
  build(l,mid,id<<1);
  build(mid+1,r,id<<1|1);
  tr[id]=tr[id<<1]+tr[id<<1|1];
}
void modify(int l,int r,int pos,int v,int id){
  if(l==r){
    tr[id]=v;
    return;
  }
  int mid=l+r>>1;
  if(pos<=mid) modify(l,mid,pos,v,id<<1);
  else modify(mid+1,r,pos,v,id<<1|1);
  tr[id]=tr[id<<1]+tr[id<<1|1];
}
int query(int l,int r,int v,int id){
  if(l==r) return l;
  int mid=l+r>>1;
  if(tr[id<<1]>=v){
    return query(l,mid,v,id<<1);
  }else{
    return query(mid+1,r,v-tr[id<<1],id<<1|1);
  }
}
signed main(){
  cin>>n;
  int tmp;
  for(int i=1;i<=n;i++) cin>>p[i];
  build(1,n,1);
  for(int i=n;i;i--){
    tmp=query(1,n,p[i],1);
    ans[tmp]=i;
    modify(1,n,tmp,0,1);
  }
  for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}
