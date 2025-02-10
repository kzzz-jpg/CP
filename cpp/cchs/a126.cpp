#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int a[200500],qr[200500];
int fa[200500],sz[200500];
int mx[200500];
int ans=0;
int Ans[200500];
bool vs[200500];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void cb(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	if(sz[a]>sz[b]) swap(a,b);
	fa[a]=b;
	mx[b]=max(mx[b],mx[a]);
	sz[b]+=sz[a];
	ans=max(ans,mx[b]*sz[b]);
}
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),vs[i]=1,fa[i]=i,sz[i]=1,mx[i]=a[i];
	for(int i=1;i<=q;i++) scanf("%lld",&qr[i]),vs[qr[i]]=0;
	for(int i=1;i<=n;i++) if(vs[i]) ans=max(ans,a[i]);
	for(int i=1;i<=n;i++){
		if(!vs[i]) continue;
		if(i-1>=1&&vs[i-1]) cb(i-1,i);
		if(i+1<=n&&vs[i+1]) cb(i,i+1);
	}
	for(int i=q;i>=1;i--){
		Ans[i]=ans;
		vs[qr[i]]=1;
		ans=max(ans,a[qr[i]]);
		if(qr[i]-1>=1&&vs[qr[i]-1]) cb(qr[i],qr[i]-1);
		if(qr[i]+1<=n&&vs[qr[i]+1]) cb(qr[i],qr[i]+1);
	}
	for(int i=1;i<=q;i++) printf("%lld\n",Ans[i]);
}
