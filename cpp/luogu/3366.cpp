#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[5050],sz[5050],liantong,n,ans,m;
struct rd{
	int x,y,v;
	bool operator < (rd o) const{
		return v<o.v;
	}
} r[200500];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void cb(int a,int b,int ct){
	a=find(a),b=find(b);
	if(a==b) return;
	if(sz[a]>sz[b]) swap(a,b);
	liantong--;
	fa[a]=b;
	ans+=ct;
	sz[b]+=sz[a];
}
signed main(){
	cin>>n>>m;
	liantong=n;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		cin>>r[i].x>>r[i].y>>r[i].v;
	}
	sort(r+1,r+1+m);
	for(int i=1;i<=m;i++){
		cb(r[i].x,r[i].y,r[i].v);
	}
	if(liantong>1) cout<<"orz\n";
	else cout<<ans<<'\n';
}
