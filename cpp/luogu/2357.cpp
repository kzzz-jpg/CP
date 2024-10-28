#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200500];
int tr[1000000];
int lz[1000000];
void push(int l,int r,int id){
	int mid=l+r>>1;
	tr[id<<1]+=lz[id]*(mid-l+1);
	tr[id<<1|1]+=lz[id]*(r-mid);
	lz[id<<1]+=lz[id];
	lz[id<<1|1]+=lz[id];
	lz[id]=0;
}
void build(int l,int r,int id){
	if(l==r) {
		tr[id]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	tr[id]=tr[id<<1]+tr[id<<1|1];
}
int query(int l,int r,int L,int R,int id){
	if(l>R||r<L) return 0;
	if(l<r) push(l,r,id);
	if(L<=l&&r<=R){
	       	return tr[id];
	}
	int mid=l+r>>1;
	return query(l,mid,L,R,id<<1)+query(mid+1,r,L,R,id<<1|1);
}
void upd(int l,int r,int L,int R,int v,int id){
	if(L>r||R<l) return;
	if(l<r) push(l,r,id);
	if(L<=l&&r<=R) {
		tr[id]+=(r-l+1)*v;
		lz[id]=v;
		return;
	}
	int mid=l+r>>1;
	upd(l,mid,L,R,v,id<<1);
	upd(mid+1,r,L,R,v,id<<1|1);
	tr[id]=tr[id<<1]+tr[id<<1|1];
}
int n,q;

signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,n,1);
	int l,r,k,op;
	while(q--){
		cin>>op;
		if(op==1){
			cin>>l>>r>>k;
			upd(1,n,l,r,k,1);
		}
		if(op==2){
			cin>>k;
			upd(1,n,1,1,k,1);
		}
		if(op==3){
			cin>>k;
			upd(1,n,1,1,-k,1);
		}
		if(op==4){
			cin>>l>>r;
			cout<<query(1,n,l,r,1)<<'\n';
		}
		if(op==5){
			cout<<query(1,n,1,1,1)<<'\n';
		}
	}
}
