#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IT set<ODT>::iterator
struct ODT{
	int l,r;
	mutable int v;
	bool operator < (ODT ano) const{
		return l<ano.l;
	}
	ODT(int L,int R=-1,int V=0):l(L),r(R),v(V){}
};
set<ODT> s;
int n,m,q,x,y,w,op;
IT split(int pos){
	IT it=s.lower_bound(ODT(pos));
	if(it!=s.end()&&it->l==pos) return it;
	it--;
	int l=it->l,r=it->r,v=it->v;
	s.erase(it);
	s.insert(ODT(l,pos-1,v));
	return s.insert(ODT(pos,r,v)).first;
}
void update(int l,int r,int v){
	IT R=split(r+1),L=split(l);
	s.erase(L,R);
	s.insert(ODT(l,r,v));
}
int query(int l,int r){
	IT R=split(r+1),L=split(l);
	int ret=0;
	map<int,int> mp;
	for(;L!=R;L++){
		if(mp[L->v]++==0) ret++;
	}
	if(mp[0]) ret--;
	return ret;
}
signed main(){
	cin>>n>>m>>q;
	m+=q;
	s.insert(ODT(1,n+1,0));
	while(m--){
		cin>>op;
		if(op==1){
			cin>>x>>y>>w;
			update(x,y,w);
		}else{
			cin>>x>>y;
			cout<<query(x,y)<<'\n';
		}
	}
}
