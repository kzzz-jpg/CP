#include<bits/stdc++.h>
using namespace std;
int hd[200500],nxt[400500],to[400500];
char c[200500],dpt[200500],fa[200500];
pair<char,int> mp[7]={{'R',0},{'O',0},{'Y',0},{'G',0},{'B',0},{'I',0},{'V',0}};
map<char,int> id;
int cnt=1;
int n,q;
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
void dfs(int x,int par,int d){
	dpt[x]=d;
	fa[x]=par;
	for(int e=hd[x];e;e=nxt[e]){
		if(to[e]!=par){
			dfs(to[e],x,d+1);
		}
	}
}
signed main(){
	id['R']=0;
	id['O']=1;
	id['Y']=2;
	id['G']=3;
	id['B']=4;
	id['I']=5;
	id['V']=6;
	cin>>n;
	int x,y;
	for(int i=0;i<n-1;i++) cin>>x>>y,addE(x,y),addE(y,x);
	dfs(0,0,1);
	cin>>q;
	char col;
	while(q--){
		cin>>x>>y>>col;
		while(dpt[x]>dpt[y]){
			if(c[x]!=col){
				mp[id[col]].second++;
				c[x]=col;
			}
			x=fa[x];
		}
		while(dpt[y]>dpt[x]){
			if(c[y]!=col){
				mp[id[col]].second++;
				c[y]=col;
			}
			y=fa[y];
		}
		while(x!=y){
			if(c[y]!=col){
				mp[id[col]].second++;
				c[y]=col;
			}
			y=fa[y];
			if(c[x]!=col){
				mp[id[col]].second++;
				c[x]=col;
			}
			x=fa[x];
		}
	}
	for(int i=0;i<7;i++){
		if(mp[i].second==0) continue;
		cout<<mp[i].first<<' '<<mp[i].second<<'\n';
	}
}
