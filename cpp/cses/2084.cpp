#include<bits/stdc++.h>
using namespace std;
#define int long long
struct line{
	int a,b;
	line(int A=0,int B=0):a(A),b(B){}
	int operator()(int x){return a*x+b;}
} ln[200500];
int n,m,f[200500],s[200500],dp[200500];
int tr[4000500];
void addln(int x,int id,int l,int r){
	if(l==r) {
		if(ln[tr[id]](l)>ln[x](l)) swap(x,tr[id]);
		return;
	}
	int mid=(l+r)>>1;
	if(ln[tr[id]](mid)>ln[x](mid)) swap(x,tr[id]);
	if(ln[tr[id]](l)<ln[x](l)&&ln[tr[id]](r)<ln[x](r)) return;
	if(ln[tr[id]](l)>ln[x](l)) addln(x,id<<1,l,mid);
	else addln(x,id<<1|1,mid+1,r);
}
int query(int x,int id,int l,int r){
	if(l==r) return ln[tr[id]](x);
	int mid=(l+r)>>1;
	if(x<=mid) return min(ln[tr[id]](x),query(x,id<<1,l,mid));
	else return min(ln[tr[id]](x),query(x,id<<1|1,mid+1,r));
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>f[i];
	ln[0]=line(m,0);
	for(int i=1;i<=n;i++){
		dp[i]=query(s[i],1,0,1000000);
		ln[i]=line(f[i],dp[i]);
		addln(i,1,0,1000000);
	}
	cout<<dp[n]<<'\n';
}
