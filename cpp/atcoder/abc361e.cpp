#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt=1;;
int sum,x,y,v;
int hd[200500],nxt[400500],to[400500],w[400500];
void addE(int a,int b,int c){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	w[cnt]=c;
	hd[a]=cnt++;
}
int st,farn,maxd;
void dfs(int x,int par,int d){
	if(d>maxd) farn=x,maxd=d;
	for(int e=hd[x];e;e=nxt[e]){
		if(to[e]!=par){
			dfs(to[e],x,d+w[e]);
		}
	}
}

signed main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y>>v;
		addE(x,y,v);
		addE(y,x,v);
		sum+=v;
	}
	st=0,farn=-1,maxd=-1;
	dfs(1,0,0);
	st=farn,farn=-1,maxd=-1;
	dfs(st,0,0);
	int ans=sum*2-maxd;
	cout<<ans<<'\n';
}
