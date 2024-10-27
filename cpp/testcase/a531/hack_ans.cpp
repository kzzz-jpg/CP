#include<bits/stdc++.h>
using namespace std;
int fa[200500],sz[200500];
int n,m;
void init(){
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void cb(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	fa[a]=b;
	sz[b]+=sz[a];
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	init();
	int op,x,y;
	while(m--){
		cin>>op>>x>>y;
		if(op&1) cb(x,y);
		else{
			if(find(x)^find(y)) cout<<-1<<'\n';
			else cout<<sz[find(x)]<<'\n';
		}
	}
}
