#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,k,ans;
int g[500][500];
int a[6];
struct rd{
	int x,y,w;
} rad[200500];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=1e15;
		}
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
int getn(int a[],int tm){
	int nw=1,ret=0;
	for(int i=1;i<=tm;i++){
		cout<<nw<<' ';
		if(g[nw][rad[a[i]].x]<g[nw][rad[a[i]].y]){
			ret+=g[nw][rad[a[i]].x]+rad[i].w;
			nw=rad[a[i]].y;
		}else{
			ret+=g[nw][rad[a[i]].y]+rad[i].w;
			nw=rad[a[i]].x;
		}
		cout<<nw<<'\n';
	}
	return ret+g[nw][n];
}
signed main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++) {
		cin>>rad[i].x>>rad[i].y>>rad[i].w;
		g[rad[i].x][rad[i].y]=g[rad[i].y][rad[i].x]=min(g[rad[i].x][rad[i].y],rad[i].w);
	}
	floyd();
	cin>>q;
	while(q--){
		cin>>k;
		for(int i=1;i<=k;i++) cin>>a[i];
		ans=1e15;
		do{
			ans=min(ans,getn(a,k));
		}while(next_permutation(a+1,a+1+k));
		cout<<ans<<'\n';
	}
}

