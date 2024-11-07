#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[200500],qr[200500];
int fa[200500],sz[200500];
int mx[200500];
int ans=0;
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
	for(int i=1;i<=n;i++) cin>>a[i],vs[i]=1,fa[i]=i,mx[i]=a[i];
	for(int i=1;i<=q;i++) cin>>qr[i],vs[qr[i]]=0;
	for(int i=1;i<n;i++){
		if(!vs[i]) continue;
		if(!vs[i+1]) cb(i,i+1);
	}
	reverse(qr+1,qr+1+q);
	for(int i=1;i<=q;i++){
		cout<<ans<<'\n';
		vs[qr[i]]=1;
		if(vs[qr[i]]) cb(qr[i],qr[i-1]);
		if(vs[qr[i+1]])cb(qr[i],qr[i+1]);
	}
}
