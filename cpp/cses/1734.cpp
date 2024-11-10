#include<bits/stdc++.h>
using namespace std;
int n,a[200500],q,cnt[200500],pos[200500];;
int kui;
int ans[200500],nw;
struct qr{
	int l,r,id;
	bool operator < (qr o) const{
		if(pos[l]==pos[o.l]) return r<o.r;
		return l<o.l;
	}
} qry[200500];
void add(int x){
	if(cnt[a[x]]++==0) nw++;
}
void del(int x){
	if(--cnt[a[x]]==0) nw--;
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	kui=sqrt(n);
	for(int i=1;i<=n;i++) cin>>a[i],pos[i]=i/kui+1;
	vector<int> lsh(a+1,a+1+n);
	sort(lsh.begin(),lsh.end());
	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
	for(int i=1;i<=n;i++) a[i]=lower_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin()+1;
	for(int i=1;i<=q;i++) cin>>qry[i].l>>qry[i].r,qry[i].id=i;
	sort(qry+1,qry+1+q);
	for(int i=1,l=1,r=0;i<=q;i++){
		while(r<qry[i].r) add(++r);
		while(r>qry[i].r) del(r--);
		while(l>qry[i].l) add(--l);
		while(l<qry[i].l) del(l++);
		ans[qry[i].id]=nw;
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}
