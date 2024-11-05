#include<bits/stdc++.h>
using namespace std;
int n,m,q,s,t,hp=0,st,de,_hp,_st,_de;
char g[102][102];
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>g[i][j];
	}
	cin>>_hp>>_st>>_de;
	cin>>s>>t;
	cin>>st>>de;
	cin>>q;
	int op,fc;
	while(q--){
		cin>>op;
		if(op==1){
			cout<<hp<<' '<<st<<' '<<de<<'\n';
		}else{
			cin>>fc;
			fc--;
			s=s+dir[fc][0];
			t=t+dir[fc][1];
			if(g[s][t]=='R'){
				hp=max(0,hp-10);
			}else if(g[s][t]=='Q'){
				st+=5;
			}else if(g[s][t]=='Y'){
				de+=5;
			}else if(g[s][t]=='M'){
				int nw=ceil(_hp*1.0/max(1,st-_de));
				hp+=max(1,nw)*max(1,_st-de);
			}
		}
	}
}
