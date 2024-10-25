#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,ans=0;
int fa[200500],mx[200500],sz[200500];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void cb(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	if(sz[a]>sz[b]) swap(a,b);
	fa[a]=b;
	sz[b]+=sz[a];
	mx[b]=max(mx[b],mx[a]);
	ans=max(ans,mx[b]*sz[b]);
}
bool chk(int a,int b){
	a=find(a),b=find(b);
	return a==b;
}
struct Qur{
	int ans;
	int op;
} qr[200500];
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>mx[i];
		fa[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=q;i++){
		cin>>qr[i].op;
		fa[qr[i].op]=-1;
	}
	reverse(qr+1,qr+1+q);
	fa[0]=-1;
	fa[n+1]=-1;
	for(int i=1;i<=n;i++){
		if(fa[i]==-1) continue;
		if(fa[i-1]!=-1) cb(i,i-1);
		if(fa[i+1]!=-1) cb(i,i+1);
	}
	for(int i=1;i<=q;i++){
		if(fa[qr[i].op-1]!=-1)cb(qr[i].op,qr[i].op-1);
		if(fa[qr[i].op+1]!=-1)cb(qr[i].op,qr[i].op+1);
		qr[i].ans=ans;
	}
	for(int i=q;i>=1;i--){
		cout<<qr[i].ans<<'\n';
	}
}
