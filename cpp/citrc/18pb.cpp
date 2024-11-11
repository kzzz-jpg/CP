#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
int hd[200500],nxt[400500],to[400500],dpt[400500];
int cnt=1;
int n,q;
int rl[200500];
string yesno[2]={"no\n","yes\n"};
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
int bz[25][200500];
void dfs(int x,int par,int d){
	dpt[x]=d;
	bz[0][x]=par;
	for(int e=hd[x];e;e=nxt[e]){
		if(to[e]!=par) dfs(to[e],x,d+1);
	}
}
void init_bz(){
	for(int i=1;i<=n;i++) rl[i]=i;
	for(int k=1;k<25;k++){
		for(int i=1;i<=n;i++){
			bz[k][i]=bz[k-1][bz[k-1][i]];
		}
	}
}
int qry(int x,int y){
	if(dpt[x]>dpt[y]) return 0;
	if(dpt[x]==dpt[y]) return x==y;
	int h=dpt[y]-dpt[x];
	for(int i=0;i<25;i++){
		if((h>>i)&1) y=bz[i][y];
	}
	return x==y;
}
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	int op,x,y;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		addE(x,y);
		addE(y,x);
	}
	dfs(1,0,1);
	init_bz();
	cin>>q;
	while(q--){
		cin>>op>>x>>y;
		if(op==2){
			cout<<yesno[(qry(rl[x],rl[y]))];
		}else{
			swap(rl[x],rl[y]);
		}
	}
}
