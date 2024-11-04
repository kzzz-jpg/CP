#include<bits/stdc++.h>
#define int long long
using namespace std;
int pos[200500];
struct qr{
	int l,r,id;
	qr(int L=0,int R=0,int I=0):l(L),r(R),id(I){}
	bool operator < (qr o) const{
		if(pos[l]==pos[o.l]) return r<o.r;
		return l<o.l;
	}
} q[200500];
int cnt[200500];
int N,Q,a[200500],Ans;
int ans[200500];
int calc(int x){
	if(cnt[x]<3) return 0;
	return cnt[x]*(cnt[x]-1)*(cnt[x]-2)/6;
}
void add(int x){
	Ans-=calc(a[x]);
	cnt[a[x]]++;
	Ans+=calc(a[x]);
}
void del(int x){
	Ans-=calc(a[x]);
	cnt[a[x]]--;
	Ans+=calc(a[x]);
}
signed main(){
	cin>>N>>Q;
	int kui=sqrt(N);
	for(int i=1;i<=N;i++){
		cin>>a[i];
		pos[i]=i/kui+1;
	}
	for(int i=1;i<=Q;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+1+Q);
	for(int i=1,l=1,r=0;i<=Q;i++){
		while(r<q[i].r) add(++r);
		while(r>q[i].r) del(r--);
		while(l>q[i].l) add(--l);
		while(l<q[i].l) del(l++);
		ans[q[i].id]=Ans;
	}
	for(int i=1;i<=Q;i++) cout<<ans[i]<<'\n';
}
