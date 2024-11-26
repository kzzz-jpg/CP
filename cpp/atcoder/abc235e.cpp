#include<bits/stdc++.h>
#define int long long
using namespace std;
struct rd{
	int v,a,b;
	bool operator < (rd o) const{
		return v<o.v;
	}
} r[200500];
int hd[200500],nxt[400500],to[400500],w[400500];
int cnt=1;
void addE(int a,int b,int v){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	w[cnt]=v;
	hd[a]=cnt++;
}
int fa[200500],sz[200500],dpt[200500];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void cb(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	if(sz[a]>sz[b]) swap(a,b);
	fa[a]=b;
	sz[b]+=a;
}
int bz[24][200500],fbz[24][200500];
void dfss(int x,int par,int d){
	dpt[x]=d;
	fbz[0][x]=par;
	for(int e=hd[x];e;e=nxt[e]){
		if(to[e]!=par){
			bz[0][to[e]]=w[e];
			dfss(to[e],x,d+1);
		}
	}
}
int qry(int a,int b){
	int lmx=0,rmx=0;
	for(int i=23;i>=0;i--){
		while(dpt[fbz[i][a]]>dpt[b]) lmx=max(lmx,bz[i][a]),a=fbz[i][a];
	}
	for(int i=23;i>=0;i--){
		while(dpt[fbz[i][b]]>dpt[a]) rmx=max(rmx,bz[i][b]),b=fbz[i][b];
	}
	for(int i=23;i>=0;i--){
	       	if(fbz[i][a]!=fbz[i][b]){
		       	lmx=max(lmx,bz[i][a]),rmx=max(rmx,bz[i][b]),a=fbz[i][a],b=fbz[i][b];
		}
	}
	lmx=max(lmx,bz[0][a]);
	rmx=max(rmx,bz[0][b]);
	return max(rmx,lmx);
}
int n,m,q;
signed main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        for(int i=1;i<=m;i++){
		cin>>r[i].a>>r[i].b>>r[i].v;
	}
	sort(r+1,r+1+m);
	for(int i=1;i<=m;i++){
		if(find(r[i].a)==find(r[i].b)) continue;
		cb(r[i].a,r[i].b);
		addE(r[i].a,r[i].b,r[i].v);
		addE(r[i].b,r[i].a,r[i].v);
	}	
	dfss(1,1,1);
	for(int i=1;i<24;i++){
		for(int j=1;j<=n;j++){
			fbz[i][j]=fbz[i-1][fbz[i-1][j]];
			bz[i][j]=max(bz[i-1][j],bz[i-1][fbz[i-1][j]]);
		}
	}
	/*
	cerr<<"-----------------------------------------------"<<'\n';
	for(int i=0;i<24;i++){
		for(int j=1;j<=n;j++) cerr<<fbz[i][j]<<' ';
		cerr<<'\n';
	}
	cerr<<"-----------------------------------------------"<<'\n';
	*/
	int a,b,c;
	while(q--){
		cin>>a>>b>>c;
		if(qry(a,b)>c){
			cout<<"Yes\n";
		}
		else cout<<"No\n";
	}
}
