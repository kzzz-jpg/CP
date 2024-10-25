#include<bits/stdc++.h>
using namespace std;
int tr[400500],n,m,l,r,v;
map<int,int> mp;
int ans=0;
void push(int id){
	if(tr[id]) tr[id<<1]=tr[id<<1|1]=tr[id];
	tr[id]=0;
}
void update(int l,int r,int L,int R,int w,int id){
       if(L>r||R<l) return;       
       if(l<r) push(id);
       if(L<=l&&r<=R){
	       tr[id]=w;
	       return;
       }
       int mid=(l+r)>>1;
       update(l,mid,L,R,w,id<<1);
       update(mid+1,r,L,R,w,id<<1|1);
}
int query(int l,int r,int pos,int id){
	if(l<r) push(id);
	if(l==r){
		return tr[id];
	}
	int mid=(l+r)>>1;
	if(pos>mid) return query(mid+1,r,pos,id<<1|1);
	else return query(l,mid,pos,id<<1);
}
signed main(){
	cin>>n>>m;
	while(m--){
		cin>>l>>r>>v;
		update(1,n,l,r,v,1);
	}
	for(int i=1;i<=n;i++){
		if(mp[query(1,n,i,1)]++==0) ans++;
	}
	if(mp[0]) ans--;
	cout<<ans<<'\n';
}
