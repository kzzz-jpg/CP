#include<bits/stdc++.h>
#define int long long
using namespace std;
int tr[400500],n,m,l,r,v,nw=0,q;
int arr[100500];
int ans[100500];
int kui[10000];
int vs[100500]={0};
int bksz;
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
struct qry{
	int l,r,id;
	bool operator < (qry ano) const{
		if(kui[l]==kui[ano.l]) return r<ano.r;
		return l<ano.l;
	}
} qr[100500];
void add(int pos){
	assert(arr[pos]<=100000);
	if(vs[arr[pos]]++==0) nw++;
}
void del(int pos){
	assert(arr[pos]<=100000);
	if(--vs[arr[pos]]==0) nw--;
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;
	bksz=sqrt(n);
	while(m--){
		cin>>l>>r>>v;
		update(1,n,l,r,v,1);
	}
	for(int i=1;i<=n;i++){
		arr[i]=query(1,n,i,1);
		kui[i]=i/bksz+1;
	}
	for(int i=1;i<=q;i++){
		cin>>qr[i].l>>qr[i].r;
		qr[i].id=i;
	}
	sort(qr+1,qr+1+q);
	for(int i=1,ll=1,rr=0;i<=q;i++){
		while(rr<qr[i].r) add(++rr);
		while(rr>qr[i].r) del(rr--);
		while(ll>qr[i].l) add(--ll);
		while(ll<qr[i].l) del(ll++);
		ans[qr[i].id]=nw;
		//if(vs[0]) ans[qr[i].id]--;
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}
